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

#define max_v 310000
#define LOGN 50
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << (n))
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) | 1)
#define RC(n) (((n) << 1) + 2)
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}


int sum[max_v * LOGN], lc[max_v * LOGN], rc[max_v * LOGN]; //d is max
int arr[max_v], srt[max_v], root[max_v], n, s, ind, ans;

void dup(int& k){
  ind++;
  sum[ind] = sum[k];
  lc[ind] = lc[k];
  rc[ind] = rc[k];
  k = ind;
}

int get_ind(int key){
  return lower_bound(srt, srt + n, key) - &srt[0];
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


void dfs(int k1, int k2, int kth, int L, int R){
  if(R <= L || sum[k2] - sum[k1] < kth) return ;
  
  if(L + 1 == R){
    if(sum[k2] - sum[k1] >= kth) ans = min(ans, L);
    return ;
  }

  int mid = (L + R) / 2;
  dfs(lc[k1], lc[k2], kth, L, mid);
  if(ans == int_max) dfs(rc[k1], rc[k2], kth, mid, R);
}

void pre_process(){
  s = pow_2((int)(ceil(log2(n))));
  ind = s*2;
  root[0] = 0;
  for(int i = 0; i < s - 1; i++){
    lc[i] = LC(i);
    rc[i] = RC(i);
    srt[i] = arr[i];
  }
  
  sort(srt, srt + n);

  for(int i = 1; i<=n; i++){
    root[i] = root[i - 1];
    U(get_ind(arr[i - 1]), 1, root[i], 0, s);
  }
}


int main(){
	
  int n, q;
  scanf("%d%d", &n, &q);
  
  for(int i = 0; i<n; i++){
    scanf("%d", &arr[i]);
  }

  pre_process();

  while(q--){
    int a, b, c;
    ans = int_max;
    scanf("%d%d%d", &a, &b, &c);
    int kth = (b - a + 1)/ c + 1;
    dfs(root[a - 1], root[b], kth, 0, s);
    if(ans == int_max) printf("-1\n");
    else printf("%d\n", srt[ans]);
  }

  


	return 0;
}

