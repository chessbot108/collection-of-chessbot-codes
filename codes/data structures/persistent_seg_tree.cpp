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

#define max_v 1100000
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) ((int)(1 << (n)))
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

long long sum[max_v * pow_2(5)];
int lc[max_v * pow_2(5)], rc[max_v * pow_2(5)], root[max_v];
int ind = 0;
void dup(int& k){
  ind++;
  lc[ind] = lc[k];
  rc[ind] = rc[k];
  sum[ind] = sum[k];
  k = ind;
}

void U(int p, long long val, int& k, int L, int R){
  if(p < L || R <= p || R <= L) return ;
  dup(k);
  if (L + 1 == R){
    sum[k] = val;
    assert(L == p);
    return ;
  }
  int mid = (L + R) / 2;
  U(p, val, lc[k], L, mid);
  U(p, val, rc[k], mid, R);
  sum[k] = sum[lc[k]] + sum[rc[k]];

}

void U(int qL, int qR, int&k, int val, int L, int R){
  if(qR <= L || R <= qL || R <= L) return ;
  dup(k);
  if(qL <= L && R <= qR){
    sum[k] += val;
    return ;
  }
  int mid = (L + R) / 2;
  U(qL, qR, lc[k], L, mid);
  U(qL, qR, rc[k], mid, R);
  sum[k] = sum[lc[k]] + sum[rc[k]];
}

long long Q(int qL, int qR, int k, int L, int R){
  if(qR <= L || R <= qL || R <= L) return 0ll;
  if(qL <= L && R <= qR) return sum[k];
  int mid = (L + R) / 2;
  return Q(qL, qR, lc[k], L, mid) + Q(qL, qR, rc[k], mid, R);
}

int main(){
	
  int n, q;
  scanf("%d%d", &n, &q);
  int s = pow_2((int)(ceil(log2(n))));
  ind = s*2 + 1;
  for(int i = 0; i<n; i++){
    scanf("%lld", &sum[i + (s - 1)]);
  }

  for(int i = s - 2; i >= 0; i--){
    sum[i] = sum[LC(i)] + sum[RC(i)];
    lc[i] = LC(i);
    rc[i] = RC(i);
    printf("%lld %lld\n", sum[LC(i)], sum[RC(i)]);
  }
  

  
	return 0;
}

