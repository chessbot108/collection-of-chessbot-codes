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

#define max_v 110000
#define LOGN 50
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) | 1)
#define RC(n) (((n) << 1) + 2)
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int lc[max_v * LOGN];
int rc[max_v * LOGN];
int sum[max_v * LOGN];

int arr[max_v], srt[max_v], root[max_v];
int n, s, ind;

inline int get_ind(int key){
  return lower_bound(srt, srt + n, key) - &srt[0];
}

void dup(int& k){
  ind++;
  lc[ind] = lc[k];
  rc[ind] = rc[k];
  sum[ind] = sum[k];
  k = ind;
}

void U(int p, int val, int& k, int L, int R){
  if(p < L || R <= p || R <= L) return ;
  
  dup(k);
  if(L + 1 == R){
    sum[k] += val;
    return ;
  }

  int mid = (L + R) / 2;
  U(p, val, lc[k], L, mid);
  U(p, val, rc[k], mid, R);
  sum[k] = sum[lc[k]] + sum[rc[k]];
}

int bin_search(int kth, int k1, int k2, int L, int R){
  if(L + 1 == R) return srt[L];
  assert(kth >= 0);
  int t = sum[lc[k2]] - sum[lc[k1]], mid = (L + R) / 2;
  printf("%d %d %d %d %d %d %d\n", sum[k1], sum[k2], t, k1, k2, L, R);
  if(t < kth){
    return bin_search(kth  - t, rc[k1], rc[k2], mid, R); 
  }else{
    return bin_search(kth, lc[k1], lc[k2], L, mid);
  }
}

void pre_process(){
  s = pow_2((int)(ceil(log2(n))));
  ind = s*2;
  root[0] = 0;

  for(int i = 0; i<s; i++){
    srt[i] = arr[i];
    lc[i] = LC(i);
    rc[i] = RC(i);
  }
  sort(srt, srt + n);

  for(int i = 1; i<=n; i++){
    root[i] = root[i - 1];
    U(get_index(arr[i - 1]), 1, 0, s);
  }
}


int main(){
	int q;
  scanf("%d%d", &n, &q);
  
  for(int i = 0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  pre_process();
  
  while(q--){ //assuming queries are 1 based inclusive
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", bin_search(c, root[a - 1], root[b], 0, s));
  }
  


	return 0;
}

