#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <list>
#include <queue>
#include <stack>
//#include <unordered_map>
//#include <unordered_set>
#include <functional>

#define max_v 410000
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) | 1)
#define RC(n) (((n) << 1) + 2)
#define LOG2(n) ((int)ceil(log2((n))))
using namespace std;
const long long MOD = 10007;
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

long long add[max_v], mult[max_v], set_tag[max_v];
long long sum1[max_v], sum2[max_v], sum3[max_v];
bool marked[max_v];

void tag(long long k, long long len, long long a, long long b, long long c){
  //a is set
  //b is mult
  //c is add
  assert(k >= 0ll && len > 0ll);
  
  if (a) { // a != -1
      set_tag[k] = a;
      mult[k] = b;
      add[k] = c;
      long long p = (a * b + c) % MOD;
      sum1[k] = p * len % MOD;
      sum2[k] = p * sum1[k] % MOD;
      sum3[k] = p * sum2[k] % MOD;
      marked[k] = true;
  } else {
      (mult[k] *= b) %= MOD;
      ((add[k] *= b) += c) %= MOD;
      (sum1[k] *= b) %= MOD;
      (sum2[k] *= b * b % MOD) %= MOD;
      (sum3[k] *= b * b % MOD * b % MOD) %= MOD;
      long long c2 = c * c % MOD, c3 = c * c2 % MOD;
      (sum3[k] += c * sum2[k] % MOD * 3ll + c2 * sum1[k] % MOD * 3ll + c3 * len % MOD) %= MOD;
      (sum2[k] += c * sum1[k] % MOD * 2ll + c2 * len % MOD) %= MOD;
      (sum1[k] += c * len % MOD) %= MOD;
  }
  
}

void update(int k){
  sum1[k] = (sum1[LC(k)] + sum1[RC(k)]) % MOD;
  sum2[k] = (sum2[LC(k)] + sum2[RC(k)]) % MOD;
  sum3[k] = (sum3[LC(k)] + sum3[RC(k)]) % MOD;
}


void push_down(int k, int L, int R){
  if(L + 1 == R) return;
  int mid = (L + R) / 2;
  tag(LC(k), (long long)mid - L, set_tag[k], mult[k], add[k]);
  tag(RC(k), (long long)R - mid, set_tag[k], mult[k], add[k]);
  mult[k] = 1ll;
  add[k] = 0ll;
  set_tag[k] = 0ll;
  marked[k] = false;
  update(k);
}


void U(int qL, int qR, int k, long long val, int t, int L, int R){
  //printf("%d %d, %d %d, %lld %lld %lld %d\n", qL, qR, L, R, sum1[k], sum2[k], sum3[k], (int)(qL <= L && R <= qR));
  if(R <= L || qR <= L || R <= qL) return ;
  if(qL <= L && R <= qR){
    if(t == 1){ //set
      tag(k, R - L, val, 1ll, 0ll);
    }else if(t == 2){ //mult
      tag(k, R - L, 0ll, val, 0ll);
    }else{ //add
      tag(k, R - L, 0ll, 1ll, val);
    }
    return ;
  }
  int mid = (L + R) / 2;
  push_down(k, L, R);
  U(qL, qR, LC(k), val, t, L, mid);
  U(qL, qR, RC(k), val, t, mid, R);
  update(k);  
}

long long S(int qL, int qR, int k, int t, int L, int R){
 // printf("%d %d, %d %d, %lld %lld %lld %d\n", qL, qR, L, R, sum1[k], sum2[k], sum3[k], (int)(qL <= L && R <= qR));
  if(R <= L || qR <= L || R <= qL) return 0ll;
  if(qL <= L && R <= qR){
    if(t == 1) return sum1[k] % MOD;
    if(t == 2) return sum2[k] % MOD;
    if(t == 3) return sum3[k] % MOD;
    //assert(false);
  }
  int mid = (L + R) / 2;
  push_down(k, L, R);
  return (S(qL, qR, LC(k), t, L, mid) + S(qL, qR, RC(k), t, mid, R)) % MOD;
}


int main(){
  
  int n, m;
  while(scanf("%d%d", &n, &m)){
    if(!n && !m) break;
    int s = pow_2((int)ceil(log2(n + 1)));
   // printf("%d\n", s);
    int op, a, b;
    long long c;
    
    memset(add, 0, sizeof(add));
    memset(set_tag, 0, sizeof(set_tag));
    memset(mult, 0, sizeof(mult));
    memset(sum1, 0, sizeof(sum1));
    memset(sum2, 0, sizeof(sum2));
    memset(sum3, 0, sizeof(sum3));
    memset(marked, false, sizeof(marked));
    while(m--){
      scanf("%d%d%d%lld", &op, &a, &b, &c);
      if(op == 1){
        //computer wants add
        U(a - 1, b, 0, c, 3, 0, s);
      }else if(op == 2){
        //computer wants mult
        U(a - 1, b, 0, c, 2, 0, s);
      }else if(op == 3){
        //computer wants set
        U(a - 1, b, 0, c, 1, 0, s);
      }else if(op == 4){
        int p = (int) c;
        printf("%lld\n", S(a - 1, b, 0, p, 0, s) % MOD);
      }
    }


  }


	return 0;
}

