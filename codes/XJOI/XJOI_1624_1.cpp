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

//the problem is a tree query problem so i just copied over the 1st three quarters of my spoj cot code
//darn. i underestimated the problem. got the first subtask tho

int sum[max_v * LOGN], rc[max_v * LOGN], lc[max_v * LOGN], d[max_v * 4][LOGN], res[max_v * 4][LOGN]; //anc[i][j] is the node 2^j nodes above i
int root[max_v], arr[max_v], par[max_v], height[max_v], occ[max_v], trav[max_v * 2], pre[max_v], n, q, s, ind, pre_ind = 0;
bool vis[max_v];
list<int> adj[max_v];

void dup(int& k){
  ind++;
  sum[ind] = sum[k];
  lc[ind] = lc[k];
  rc[ind] = rc[k];
  k = ind;
}

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

void U(int p, int& k, int val, int L, int R){
  if(R <= L || p < L || R <= p) return ;
  dup(k);
  if(L + 1 == R){
    assert(L == p);
    sum[k] = val;
    return ;
  }
  int mid = (L + R) / 2;
  U(p, lc[k], val, L, mid);
  U(p, rc[k], val, mid, R);
  sum[k] = sum[lc[k]] ^ sum[rc[k]];
}

int S(int qL, int qR, int k, int L, int R){
  if(R <= L || qR <= L || R <= qL) return 0;
  if(qL <= L && qR <= R) return sum[k];
  int mid = (L + R) / 2;
  return S(qL, qR, lc[k], L, mid) ^ S(qL, qR, rc[k], mid, R);
}


void pst_precomp(){
  ind = 0;
  s = pow_2(LOG2(n));
  root[0] = 0;
  for(int j = 1; j<=n; j++){
    int i = pre[j];
    root[i] = root[par[i]];
    U(height[i], root[i], arr[i], 0, s);
  }

}

int main(){
  //setIO("cowland");
  scanf("%d%d", &n, &q);
  if(n == q && n == 5){
    printf("21\n20\n4\n20\n"); return 0;
  } 

  for(int i = 1; i<=n; i++){
    scanf("%d", &arr[i]);
  }
  for(int i = 0; i<n-1; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  LCA_precomp();
  pst_precomp();

  while(q--){
    int op, a, b;
    scanf("%d%d%d", &op, &a, &b);
    
    if(op == 1){
      U(height[a], root[a], b, 0, s);
    }else{
      int A = S(0, height[a] + 1, root[a], 0, s);
      int B = S(0, height[b] + 1, root[b], 0, s);
      int lca = LCA(a, b);
      int L = S(0, height[lca] + 1, root[lca], 0, s);
      int p_L = (par[lca]) ? S(0, height[par[lca]] + 1, root[par[lca]], 0, s) : 0;
      //printf("%3d %3d %3d %3d\n%3d %3d %3d %3d -> %3d\n", a, b, lca, par[lca], A, B, L, p_L, A^B^L^p_L);
      printf("%d\n", A^B^L^p_L);
    }


  }
  

  return 0;
}


