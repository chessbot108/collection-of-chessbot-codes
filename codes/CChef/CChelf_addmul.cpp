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

#define max_v 810000
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) | 1)
#define RC(n) (((n) << 1) + 2)
using namespace std;
const long long MOD = (long long)(1e9 + 7);
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

long long sum[max_v], add[max_v], set_tag[max_v], mult[max_v], arr[max_v];
bool marked[max_v];
void tag(int k, int len, long long a, long long b, long long c){
  //a -> set
  //b -> mult
  //c -> add

  if(a){
    set_tag[k] = a;
    mult[k] = b;
    add[k] = c;
    marked[k] = true;
    sum[k] = (((a * b + c) % MOD) * (long long)len) % MOD;
  }else{
    (mult[k] = (mult[k] % MOD) * (b % MOD)) %= MOD;
    ((add[k] *= b) += c) %= MOD;
    (sum[k] *= b) %= MOD;
    (sum[k] += c * (long long)len % MOD) %= MOD;
  }
}

void update(int k){
  (sum[k] = (sum[LC(k)] % MOD) + (sum[RC(k)] % MOD)) %= MOD;
}

void push_down(int k, int L, int R){
  if(L + 1 == R) return ;
  int mid = (L + R) / 2;
  tag(LC(k), mid - L, set_tag[k], mult[k], add[k]);
  tag(RC(k), R - mid, set_tag[k], mult[k], add[k]);
  marked[k] = false;
  set_tag[k] = 0LL;
  mult[k] = 1LL;
  add[k] = 0ll;
  update(k);
}


void U(int qL, int qR, int k, int a, int b, int c, int L, int R){
  if(R <= L || qR <= L || R <= qL) return ;
  if(qL <= L && R <= qR){
    tag(k, R - L, (long long)a, (long long)b, (long long)c);
    return ;
  }
  push_down(k, L, R);
  int mid = (L + R) / 2;
  U(qL, qR, LC(k), a, b, c, L, mid);
  U(qL, qR, RC(k), a, b, c, mid, R);
  update(k);
}

long long S(int qL, int qR, int k, int L, int R){
  if(R <= L || qR <= L || R <= qL) return 0ll;
  if(qL <= L && R <= qR) return sum[k] % MOD;
  push_down(k, L, R);
  int mid = (L + R) / 2;
  return ((S(qL, qR, LC(k), L, mid) % MOD) + (S(qL, qR, RC(k), mid, R) % MOD)) % MOD;
}

int make_tree(int n){
  int s = pow_2((int)(ceil(log2(n))));
  for(int i = s - 1; i < (s - 1) + n; i++){
    sum[i] = arr[i - (s - 1)];
    mult[i] = 1ll;
  }
  
  for(int i = s - 2; i >= 0; i--){
    sum[i] = (sum[LC(i)] + sum[RC(i)]) % MOD;
    mult[i] = 1ll;
  }

  return s;
}


int main(){
	int n, q;
  scanf("%d%d", &n, &q);
  for(int i = 0; i<n; i++)
    scanf("%lld", &arr[i]);

  int s = make_tree(n);
  
  while(q--){
    int op;
    scanf("%d", &op);
    if(op == 4){
      int a, b;
      scanf("%d%d", &a, &b);
      printf("%lld\n", S(a - 1, b, 0, 0, s));
    }else{
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      if(op == 1){
        U(a - 1, b, 0, 0, 1, c, 0, s);
      }else if(op == 2){
        U(a - 1, b, 0, 0, c, 0, 0, s);
      }else{
        U(a - 1, b, 0, c, 1, 0, 0, s);
      }
    }

  }

	return 0;
}

