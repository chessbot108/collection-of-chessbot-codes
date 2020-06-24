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

#define max_v 1100
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

int get_ind(int key){
  return lower_bound(srt, srt + n, key) - &srt[0];
} 

void U(int qL, int qR, int& k, int val, int L, int R){
  if(R <= L || qR <= L || R <= qL) return ;
  dup(k);
  if(qL <= L && R <= qR){
    add[k] += val;
    return ;
  }

  int mid = (L + R) / 2;
  U(qL, qR, lc[k], val, L, mid);
  U(qL, qR, rc[k], val, mid, R);
  sum[k] = sum[lc[k]] + sum[rc[k]] + add[lc[k]] + add[rc[k]];
}

int Q(int qL, int qR, int k, int L, int R){
  if(R <= L || qR <= L || R <= qL) return 0;
  if(qL <= L && R <= qR) return sum[k] + add[k];
  int mid = (L + R) / 2;
  return Q(qL, qR, lc[k], L, mid) + Q(qL, qR, rc[k], mid, R) + (min(R, qR) - max(L, qL)) * add[k];
}

void pre_process(){
  s = pow_2(LOG2(n));
  ind = s*2;
  root[0] = 0;
  for(int i = 0; i<s - 1; i++){
    lc[i] = LC(i);
    rc[i] = RC(i);
    srt[i] = arr[i];
  }
  sort(srt, srt + n);
  
  for(int i = 1; i<=n; i++){
    root[i] = root[i - 1];
    int ind = get_ind(arr[i - 1]);
    assert(occ[ind] < i);
    U(occ[ind], i, root[i], 1, 0, s);
    occ[ind] = i;
  }
  
}

int count(int a, int b){ //0-based, exclusive
  return Q(a, a + 1, root[b], 0, s);
}

int bin_search(int L, int l, int r, int k){//returns the EXCLUSIVE right end of the largest interval that has at most k colors
  printf("%d %d %d %d %d %d\n", k, L, l, (l + r)/2, r, count(L, (l + r)/2));
  if(l >= r) return l;
  int mid = (l + r) / 2;
   if(k >= count(L, mid)){
    return bin_search(L, mid + 1, r, k);
  }else{
    return bin_search(L, l, mid, k);
  }
  

}



int main(){
	scanf("%d", &n);
  for(int i = 0; i<n; i++){
    scanf("%d", &arr[i]);    
  }
  pre_process();
  for(int i = 1; i<=n; i++){
    int L = 0, tot = 0;
    while(L < n){
      L = bin_search(L, L + 1, n, i);
      tot++;
    }
    printf("%d ", tot);
  } 


	return 0;
}

