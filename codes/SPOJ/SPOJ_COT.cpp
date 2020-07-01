#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <list>
//#include <unordered_map>
//#include <unordered_set>
#include <functional>
#include <string>

#define max_v 110000
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

int sum[max_v * LOGN], rc[max_v * LOGN], lc[max_v * LOGN], d[max_v * 4][LOGN], res[max_v * 4][LOGN]; //anc[i][j] is the node 2^j nodes above i
int root[max_v], srt[max_v], arr[max_v], par[max_v], height[max_v], occ[max_v], trav[max_v * 2], pre[max_v], n, q, s, ind, pre_ind = 0;
bool vis[max_v];
list<int> adj[max_v];

void dup(int& k){
  ind++;
  sum[ind] = sum[k];
  lc[ind] = lc[k];
  rc[ind] = rc[k];
  k = ind;
}

int get_ind(int key){ return lower_bound(srt, srt + n, key) - &srt[0]; }

void dfs(int cur, int dep){
  if(vis[cur]) return ;
  pre[++pre_ind] = cur;
  vis[cur] = true;
  height[cur] = dep;
  //for (int i=0; i<dep; i++) printf("|   "); printf("cur %d\n", cur);
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

  for(int i = 0; i<ind; i++){
    d[i][0] = height[trav[i]];
    res[i][0] = trav[i]; 
  }


  for(int i = 1; i<=LOG2(ind); i++){
    for(int j = 0; j<ind; j++){
      if(d[j][i - 1] < d[j + pow_2(i - 1)][i - 1]){
        res[j][i] = res[j][i - 1];
        d[j][i] = d[j][i - 1];
      }else{
        res[j][i] = res[j + pow_2(i - 1)][i - 1];
        d[j][i] = d[j + pow_2(i - 1)][i - 1];
      }
    }
  }
  
}

int LCA(int u, int v){
  if(u == v) return u;
  if(occ[u] < occ[v]) swap(u, v);
  int k = log2(occ[u] - occ[v]);
  u = occ[u] + 1, v = occ[v];
  return (d[v][k] < d[u - pow_2(k)][k]) ? res[v][k] : res[u - pow_2(k)][k];
}

void U(int p, int& k, int L, int R){
  if(R <= L || p < L || R <= p) return ;
  dup(k);
  if(L + 1 == R){
    assert(L == p);
    sum[k]++;
    return ;
  }
  int mid = (L + R) / 2;
  U(p, lc[k], L, mid);
  U(p, rc[k], mid, R);
  sum[k] = sum[lc[k]] + sum[rc[k]];
}

int S(int p, int k, int L, int R){
  if(R <= L || p < L || R <= p) return 0;
  if(L + 1 == R) return sum[k];
  int mid = (L + R) / 2;
  return S(p, lc[k], L, mid) + S(p, rc[k], mid, R);
}

void make_pst(){
  ind = 0;
  s = pow_2(LOG2(n));
  root[0] = 0;
  
  for(int i = 0; i<n; i++){
    srt[i] = arr[i + 1];
  }
  sort(srt, srt + n);
  /** 
  for(int i = 0; i<n; i++) printf("%d ", srt[i]);
  puts("");
  **/
  for(int j = 1; j<=n; j++){
    int i =  pre[j];
    root[i] = root[par[i]];
    //printf("par[%d] = %d, arr[%d] = %d which is hashed to %d\n", i, par[i], i, arr[i], get_ind(arr[i]));
    U(get_ind(arr[i]), root[i], 0, s);
  }
  /** 
  for(int i = 0; i <= n; i++){
    printf("version %d and par[i] = %d\n", pre[i], par[pre[i]]);
    for(int j = 0; j<n; j++)
      printf("%d ", S(j, root[pre[i]], 0, s));
    puts("");
  }
  **/
}

int Q(int k1, int k2, int lca, int p_lca, int kth, int L, int R){
  if(L + 1 == R) return srt[L];
  int mid = (L + R) / 2, dis = (sum[lc[k1]] + sum[lc[k2]]) - (sum[lc[lca]] + sum[lc[p_lca]]);
  //printf("%d + %d - %d + %d = %d, and kth is %d\n", sum[lc[k1]], sum[lc[k2]], sum[lc[lca]], sum[lc[p_lca]], dis, kth);
  if(dis > kth){
    return Q(lc[k1], lc[k2], lc[lca], lc[p_lca], kth, L, mid);
  }else{
    return Q(rc[k1], rc[k2], rc[lca], rc[p_lca], kth - dis, mid, R);
  }
}

int main(){

  scanf("%d%d", &n, &q);

  memset(height, 0x3f, sizeof(height));
  memset(d, 0x3f, sizeof(d));
  for(int i = 1; i<=n; i++)
    scanf("%d", &arr[i]);

  for(int i = 0; i<n - 1; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  LCA_precomp();
  make_pst();

  while(q--){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int lca = LCA(a, b); assert(lca);
    //printf("LCA(%d, %d) = %d. par[lca] = %d\n", a, b, lca, par[lca]);
    printf("%d\n", Q(root[a], root[b], root[lca], root[par[lca]], c - 1, 0, s));
  }

  return 0;
}

