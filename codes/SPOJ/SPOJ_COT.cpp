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
int root[max_v], srt[max_v], arr[max_v], par[max_v], height[max_v], l[max_v], r[max_v], trav[max_v * 2], n, q, s, ind;
bool vis[max_v];
list<int> adj[max_v];

void dfs(int cur, int dep, int fa){
  trav[ind] = cur;
  r[cur] = ind;
  l[cur] = min(l[cur], ind);
  height[cur] = min(height[cur], dep);
  ind++;
  while(adj[cur].size()){
    int temp = adj[cur].front(); adj[cur].pop_front();
    if(temp != fa)
      dfs(temp, dep + 1, cur);
    trav[ind] = cur;
    r[cur] = ind;
    l[cur] = min(l[cur], ind);
    height[cur] = min(height[cur], dep);
    ind++;
  }
}

void LCA_precomp(){
  dfs(1, 0, -1);
  
  for(int i = 0; i<ind; i++){
    d[i][0] = height[trav[i]];
    res[i][0] = trav[i];
    printf("%d ", trav[i]);
  }
  
  puts("");
  
  for(int i = 1; i<=LOG2(ind); i++){
    for(int j = 0; j<ind; j++){
      if(d[j][i - 1] < d[j + pow_2(i - 1)][i - 1]){
        res[j][i] = res[j][i - 1];
        d[j][i] = res[j][i - 1];
      }else{
        res[j][i] = res[j + pow_2(i - 1)][i];
        d[j][i] = d[j + pow_2(i - 1)][i];
      }
    }
  }

}

int LCA(int u, int v){
  if(u == v) return u;
  if(r[u] < l[v]) swap(u, v);
  int k = log2(r[u] - l[v]);
  u = r[u], v = l[v];
  return (d[v][k] < d[u - pow_2(k)][k]) ? res[v][k] : res[u - pow_2(k)][k];
}

int main(){
	
  scanf("%d%d", &n, &q);
  memset(l, 0x3f, sizeof(l));
  memset(height, 0x3f, sizeof(height));
  for(int i = 1; i<=n; i++)
    scanf("%d", &arr[i]);
  
  for(int i = 0; i<n - 1; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  LCA_precomp();

  while(q--){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", LCA(a, b));
  }

	return 0;
}

