#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <utility>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <queue>
#define cont continue
#define moo printf
#define oom scanf
#define mool puts("") 
#define ll long long
const ll mod = 1e9 + 7;
const int MX = 2e5 +10, LOGN = 60, int_max = 0x3f3f3f3f;

using namespace std;
//pst nuke gold. wooooooooooo
int sum[MX * LOGN], rc[MX * LOGN], lc[MX * LOGN];
int n, ind = 0, s = 1;
int arr[MX], root[MX], nex[MX], occ[MX];

void dup(int &k){
  ind++;
  sum[ind] =sum[k];
  lc[ind] = lc[k];
  rc[ind] = rc[k];
  k = ind;
}

void U(int p, int& k, int L, int R){
  if(p < L || R <= p || R <= L) return ;
  dup(k);
  if(L + 1 == R){
    assert(p == L);
    sum[k]++;
    return ;
  }
  int mid = (L + R)/2;
  U(p, lc[k], L, mid);
  U(p, rc[k], mid, R);
  sum[k] = sum[lc[k]] + sum[rc[k]];
}

int S(int qL, int qR, int k, int L, int R){
  if(qR <= L || R <= qL || R <= L) return 0;
  if(qL <= L && R <= qR) return sum[k];
  int mid = (L + R)/2;
  return S(qL, qR, lc[k], L, mid) + S(qL, qR, rc[k], mid, R);
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  while(s <= n +2) s *= 2;
  for(int i = 0; i<=n; i++) nex[i] = n +1;
  for(int i = 1; i<=n; i++){
    cin >> arr[i];
    if(occ[arr[i]]){
      nex[occ[arr[i]]] = i;
    }
    occ[arr[i]] = i;
  }
  //for(int i = 1; i<=n; i++) moo("%d ", nex[i]);
  for(int i = 1; i<=n; i++){
    root[i] = root[i - 1];
    if(nex[i] != n + 1){
      U(nex[i], root[i], 0, s);
    }
  }
  ll fail = 0ll;
  for(int i = 1; i<=n; i++){
    if(nex[i] != n + 1){
      fail += (ll)(n + 1 - nex[i]); //all the positions after nex[i] are invalid
    }
    assert(nex[i] != i);
    fail += (ll)(S(i, nex[i], root[n], 0, s) - S(i, nex[i], root[i], 0, s));
  }
  
  ll tot = (ll)(n) * (ll)(n - 1);
  tot /= 2ll;
  moo("%lld\n", tot - fail);
  
	return 0;
}


