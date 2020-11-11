//code by me


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
//#include <unordered_map>
//#include <unordered_set>
#include <functional>

#define max_v 350000

#define cont continue
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

int sum[max_v], rc[max_v], lc[max_v], root[max_v]; 
int arr[max_v], ans[max_v], par[max_v];
int q[max_v], vis[max_v], l[max_v], r[max_v], srt[max_v];
int ind = 0, s = 32768, cnt = 0, n;
vector<int> adj[max_v];

void dup(int& k){
  ind++;
  sum[ind] = sum[k];
  rc[ind] = rc[k];
  lc[ind] = lc[k];
  k = ind;
}

void U(int p, int val, int& k, int L, int R){
  assert(p > 0);
  if(p < L || R <= p) return ;
  dup(k);
  if(L + 1 == R){
    assert(L == p && val == 1);
    sum[k] += val;
    return ;
  } 
  int mid = (L + R)/2;
  U(p, val, lc[k], L, mid);
  U(p, val, rc[k], mid, R);
  sum[k] = sum[lc[k]] + sum[rc[k]];
}

int S(int p, int k, int L, int R){
  if(p < L || R <= p || R <= L) return 0;
  if(L + 1 == R) return sum[k];
  int mid = (L + R)/2;
  return S(p, lc[k], L, mid) + S(p, rc[k], mid, R);
}


int Q(int k1, int k2, int kth, int L, int R){
  if(L + 1 == R) return L;
  int mid = (L + R) / 2;
  int dis = sum[lc[k2]] - sum[lc[k1]];
  if(dis > kth){
    return Q(lc[k1], lc[k2], kth, L, mid);
  }else{
    return Q(rc[k1], rc[k2], kth - dis, mid, R);
  }
}





void dfs(int u, int p){
  if(vis[u]) return ;
  vis[u] = true;
  l[u] = cnt++;
  root[cnt] = root[cnt - 1];
  //printf("%d, par -> %d\n", u, p);
  U(arr[u], 1, root[cnt], 0, s);
  for(int v : adj[u]){
    if(v == p) cont;
    par[v] = u;
    dfs(v, u);
  }
  r[u] = cnt;
  ans[u] = Q(root[l[u]], root[r[u]], q[u] - 1, 0, s);
}



int main(){
  scanf("%d", &n);
  for(int i = 0; i<n- 1;i++){
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(int i = 1; i<=n; i++){
    scanf("%d%d", &arr[i], &q[i]);
    arr[i]++;
  }
  
  dfs(1, 0);
 /** 
  for(int i = 0; i<=cnt; i++){
    printf("layer %d:\n\t", i);
    for(int j = 0; j<10; j++){
      printf("%5d ", S(j, root[i], 0, s));
    }
    puts("");
  }
**/
  for(int i = 1; i<=n; i++){
    printf("%d\n", ans[i] - 1);
  }
  //printf("ind == %d\n", ind);
	return 0;
}

