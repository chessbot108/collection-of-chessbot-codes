#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>

#define max_v 1100
#define int_max 0x3f3f3f3f
#define cont continue
#define pow_2(n) (1 << (n))
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) ((a%mod + b%mod)%mod)
#define mul(a, b) ((a%mod * b%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))

const ll mod = 1e9 + 7;

using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}
//problem statement
//https://github.com/ftiasch/problem-setting-public/blob/master/2016-sichuan-polygon/problems/sparse-graph-shortest-path-query/statements/.pdf/english/problem.pdf
//i need: mst, lca, and floyd warshall. great
const int SQRT = 320;
vector<pii> edges, stray;
vector<int> adj[max_v], nodes;
int par[max_v], super[max_v], rep[max_v], dep[max_v], dp[300][300]; 

int find(int u){ if(u != rep[u]){ u = rep[u];} return rep[u];}
void Union(int a, int b){
  a = find(a), b = find(b);
  par[b] = a;
}

void kruskal(){
  for(int i = 0; i<=n; i++){
    par[i] = i;
  } 
  for(int i = 0; i<m; i++){
    int u = edges[i].first, v = edges[i].second;
    if(find(u) != find(v)){
      Union(u, v);
      adj[u].pb(v);
      adj[v].pb(u);
    }else{
      stray.pb(edges[i]);
      nodes.pb(u);
      nodes.pb(v);
    }
  }
  
}

//dfs to get parents
void dfs(int u, int p, int d){
  par[u] = p;
  dep[u] = d;
  for(int v : adj[u]){
    if(v != p)
      dfs(v, u, d + 1);
  }

}


//just going to use sqrt lca

void precomp(){
  dfs(1, 0, 1);
  for(int i = 1, j = 0; i<=n; i++){
    for(j = 0, super[i] = i; j < SQRT && super[i]; j++) super[i] = par[super[i]];
  }
}

void k_up(int u, int k){
  while(k > SQRT) u = super[u], k = k - SQRT;
  while(k--) u = par[u];
  return u;
}

int lca(int u, int v){
  if(dep[u] < dep[v]) swap(u, v);
  u = k_up(u, dep[u] - dep[v]);
  while(super[u] != super[v]) u =super[u], v = super[v];
  while(u != v) u = par[u], v = par[v];
  assert(u == v && u);
  return u;
}

int dist(int a, int b){
  int c = lca(a, b);
  return dep[a] + dep[b] - (dep[c] * 2);
}

void floyd(){
  memset(dp, 60, sizeof(dp));
  for(pair<int, int> e : stray){
    int u = e.first, v = e.second;
    dp[u][v] = 1;
    dp[v][u] = 1;
  }
  
}

int n, m, q;
int main(){
	cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m >> q;
  for(int i = 0; i<m; i++){
    int a, b; cin >> a >> b;
    if(a == b) cont;
    edges.pb(mp(a, b));
  }
  sort(edges.begin(), edges.end());
  m = std::unique(edges.begin(), edges.end()) - edges.begin();
	edges.resize(m);
  kruskal();
  precomp();
  sort(nodes.begin(), nodes.end());
  int k = std::unique(nodes.begin(), nodes.end()) - nodes.begin();
  nodes.resize(k);
  assert(k <= n && k <= 300);

  return 0;
}

