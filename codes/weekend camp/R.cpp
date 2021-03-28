//no alternative
//https://codeforces.com/gym/100803/attachments
//problem F
//no rating on it
//lots of fun, we went over this in class before
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <utility>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <queue>
#define cont continue

#define pow2(n) (1 << (n))
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ins insert
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define tern(a, b, c) ((a) ? (b) : (c))
//the following ones give off usaco vibes
#define pbenq priority_queue
#define moo printf
#define oom scanf
#define mool puts("") 
#define loom getline

const ll mod = 1e9 + 7;
const int MX = 1e3 +10, LOGN = 30, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int super[MX][LOGN], up[MX], repl[MX], dep[MX];
vector<pii> adj[MX];
int par[MX], n, m;
vector<pair<int, pii>> edges, span;

int find(int x){ if(x != par[x]) par[x] = find(par[x]); return par[x];}
void Union(int a, int b){ a = find(a), b = find(b); par[a] = b; }

void kruskal(){
  stable_sort(edges.begin(), edges.end());
  for(int i = 0; i<=n; i++) par[i] = i;
  for(const auto& e : edges){
    int u = e.second.first, v = e.second.second, w = e.first;
    if(find(u) != find(v)){
      adj[u].pb(mp(v, w));
      adj[v].pb(mp(u, w));
      Union(u, v);
    }else{
      span.pb(e);
    }
  }
}

void dfs(int u, int p, int w){
  super[u][0] = p;
  up[u] = w;
  dep[u] = dep[p] + 1;
  for(const auto& e : adj[u]){
    if(e.first != p)
      dfs(e.first, u, e.second);
  }
} 

void precomp(){
  for(int j = 1; j<=15; j++){
    for(int i = 1; i<=n; i++){
      super[i][j] = super[super[i][j - 1]][j - 1];
    }
  }
}

int k_up(int u, int k){
  for(int i = 15; ~i; i--){
    if(k >= pow2(i)) u = super[u][i], k = k - pow2(i);
  }
  return u;
}

int lca(int a, int b){
  if(dep[a] < dep[b]) swap(a, b);
  a = k_up(a, dep[a] - dep[b]);
  if(a == b) return a;
  for(int i = 15; ~i; i--){
    if(super[a][i] != super[b][i]) a = super[a][i], b = super[b][i];
  }
  assert(a != b); assert(super[a][0] == super[b][0]); assert(a);
  return super[a][0];
} 

void walk(int u, int l, int w){
  for(; u != l; u = super[u][0]){
    if(up[u] == w) repl[u] = 1;
  }
}

void Q(int u, int v, int w){
  int l = lca(u, v);
  walk(u, l, w);
  walk(v, l, w);
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 0; i<m; i++){
    int a, b, c; cin >> a >> b >> c;
    edges.pb(mp(c, mp(a, b)));
  }
  kruskal();
  dfs(1, 0, 0);
  precomp();
  for(const auto& e : span){
    Q(e.second.first, e.second.second, e.first);
  }
  int cnt = 0, sum = 0;
  for(int i = 2; i<=n; i++){
    if(!repl[i]){
      cnt++;
      sum += up[i];
    }
  }
  moo("%d %d\n", cnt, sum);
	return 0;
}


