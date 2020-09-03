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
#define LOGN 25
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
//bruh. this problem is SPOJ COT 2
//i would ctrl c, ctrl v, but i have standards :D
int sum[max_v * LOGN], rc[max_v * LOGN], lc[max_v * LOGN], st[max_v * 4][LOGN], res[max_v * 4][LOGN];
int root[max_v], arr[max_v], par[max_v], height[max_v], occ[max_v], trav[max_v * 2], pre[max_v], n, q, s, ind, pre_ind = 0;
bool vis[max_v];
list<int> adj[max_v];

//LCA
void dfs(int cur, int dep){
  if(vis[cur]) return ;
  pre[++pre_ind] = cur;
  vis[cur] = true;
  height[cur] = dep;
  for(int x : adj[cur]){
    if(!par[x] && x - 1) par[x] = cur;
    dfs(x, dep + 1);
    trav[ind] = cur;
    occ[cur] = ind++;
  }
}

void LCA_precomp(){
  trav[0] = 1;
  ind = 1;
  dfs(1, 0);
  memset(st, 0x3f, sizeof(st));
  for(int i = 0; i<ind; i++){
    st[i][0] = height[trav[i]];
    res[i][0] = trav[i];
  }
  for(int j = 1; j<=LOG2(ind); j++){
    for(int i = 0; i<ind; i++){
      int K = i + pow_2(j - 1);
      if(st[i][j - 1] < st[K][j - 1]){
        res[i][j] = res[i][j - 1];
        st[i][j] = st[i][j - 1];
      }else{
        res[i][j] = res[K][j - 1];
        st[i][j] = st[K][j - 1];
      }
    }
  }

}

int LCA(int u, int v){
  if(u == v) return u;
  if(occ[u] < occ[v]) swap(u, v);
  int k = log2(occ[u] - occ[v]);
  u = occ[u] + 1, v = occ[v];
  return (st[v][k] < st[u - pow_2(k)][k]) ? res[v][k] : res[u - pow_2(k)][k];
}

//seg tree

void dup(int& k){
  sum[++ind] = sum[k];
  rc[ind] = rc[k];
  lc[ind] = lc[k];
  k = ind;
}

void U(int p, int& k, int L, int R){
  if(p < L || R <= p || R <= L) return ;
  dup(k);
  if(L + 1 == R){
    assert(L == p);
    sum[k]++;
    return ;
  }
  int mid = (L + R) / 2;
  U(p, lc[k], L, mid);
  U(p, rc[k], mid, R);
  sum[k] = sum[rc[k]] + sum[lc[k]];
}

int Q(int k1, int k2, int lca, int p_lca, int p, int L, int R){
  if(p < L || R <= p || R <= L) return 0;
  if(L + 1 == R){
    assert(L == p);
    return (sum[k1] + sum[k2]) - (sum[lca] + sum[p_lca]);
  }
  int mid = (L + R) / 2;
  return Q(lc[k1], lc[k2], lc[lca], lc[p_lca], p, L, mid) + Q(rc[k1], rc[k2], rc[lca], rc[p_lca], p, mid, R);
}

void make_pst(){
  ind = 0;
  s = pow_2(LOG2(n));
  root[0] = 0;
  for(int j = 1; j<=n; j++){
    int i = pre[j];
    root[i] = root[par[i]];
    U(arr[i], root[i], 0, s);
  }
}

int main(){
	scanf("%d%d", &n, &q);
  for(int i = 1; i<=n; i++){
    scanf("%d", &arr[i]); //what makes this easier than spoj cot is that i don't have to discretize
  }
  
  for(int i = 0; i<n - 1; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  LCA_precomp();
  make_pst();
  //printf("still good\n");
  while(q--){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int lca = LCA(a, b); assert(lca);
    printf("%d", (int)((bool)(Q(root[a], root[b], root[lca], root[par[lca]], c, 0, s))));
  }
	return 0;
}

