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

#define max_v 210000
#define LOGN 50
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << (n))
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define LOG2(n) ((int)(ceil(log2((n)))))
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}
//hi
int sum[max_v * LOGN], add[max_v * LOGN], lc[max_v * LOGN], rc[max_v * LOGN];
int arr[max_v * 2], srt[max_v * 2], root[max_v * 2], occ[max_v * 2], n, s, ind;


void dup(int& k){
  ind++;
  sum[ind] = sum[k];
  add[ind] = add[k];
  lc[ind] = lc[k];
  rc[ind] = rc[k];
  k = ind;
}

void U(int p, int val, int& k, int L, int R){
  if(R <= L || p < L || R <= p) return ;
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

int S(int qL, int qR, int k, int L, int R){
  if(R <= L || qR <= L || R <= qL) return 0;
  if(qL <= L && R <= qR) return sum[k];
  int mid = (L + R) / 2;
  return S(qL, qR, lc[k], L, mid) + S(qL, qR, rc[k], mid, R);
}


void print(int v){
  printf("for version %d:\n", v);
  int r = root[v];
  for(int i = 0; i<n; i++){
    printf("%d ", S(i, i + 1, r, 0, s));
  }
  puts("");
}


void pre_process(){
  s = pow_2(LOG2(n));
  ind = s*2;
  root[n] = 0;
  for(int i = 0; i<s; i++){
    lc[i] = LC(i);
    rc[i] = RC(i);
  }
    
  for(int i = n - 1; i >= 0; i--){
    int a = arr[i];
    root[i] = root[i + 1];
    if(!occ[a]){
      U(i, 1, root[i], 0, s);
    }else{
      U(occ[a], -1, root[i], 0, s);
      U(i, 1, root[i], 0, s);
    }
    //printf("update type %d\n", (!occ[a]) ? 1 : 2);
    //printf("%d -> from %d to %d\n", a, (occ[a]) ? occ[a] : -1, i);
    //print(i);
    occ[a] = i;
  }
  //assert(false);
}

int bin_search(int kth, int k, int L, int R){
  if(L + 1 == R) return R;
  int temp = sum[lc[k]], mid = (L + R) / 2;
  assert(kth >= 0);
  if(kth <= temp){
    return bin_search(kth, lc[k], L, mid);
  }else{
    return bin_search(kth - temp, rc[k], mid, R);
  }
}
int main(){
 
  scanf("%d", &n);

  for(int i = 0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  
  pre_process();

  for(int i = 1; i <= n; i++){
    int j = 0, ans = 0;
    while(j < n){
      ans++;
      if(S(j, n, root[j], 0, s) <= i){
        break;
      }
      j = bin_search(i + 1, root[j], 0, s) - 1;
      //printf("%d \n", j);
    }
    //printf("%d ", i);
    printf("%d ", ans);
    //puts("");
    //assert(i == 1);
  }

	return 0;
}

