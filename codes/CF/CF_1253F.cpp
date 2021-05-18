//gyrating cat enthusiast
//borrowed my binlift max from
//https://codeforces.com/contest/609/submission/116193796
//100 less lines to write
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
#include <set>

#define ll long long
#define lb long double
#define pii pair<int, ll>
#define pb push_back
#define mp make_pair
#define ins insert
#define cont continue
#define siz(vec) ((int)(vec.size()))
#define int ll //war crimes wooooooooo

#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define bckt(arr, val, sz) memset(arr, val, sizeof(arr[0]) * (sz))
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define tern(a, b, c) ((a) ? (b) : (c))
#define feq(a, b) (fabs(a - b) < eps)
#define pow2(i) (1 << (i))

#define moo printf
#define oom scanf
#define mool puts("") 
#define orz assert
#define fll fflush(stdout)

const lb eps = 1e-9;
const ll mod = 1e9 + 7, ll_max = (ll)1e18;
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node{
  int u; ll w;
  node(){}
  node(int a, ll b){ u = a, w = b; }
  bool operator < (const node& b) const{
    return w > b.w;
  }
};


vector<pii> adj[MX];
vector<pair<ll, pii>> edges;
int par[MX], super[MX][40], dep[MX], vis[MX];
ll d[MX][40], dist[MX];
int n, m, k, q;

int find(int x){ if(x != par[x]) par[x] = find(par[x]); return par[x]; }
void Union(int a, int b){ a = find(a), b = find(b); par[a] = b; }
 
void mkdsu(){ for(int i = 0; i<=n; i++) par[i] = i; }
 
void kruskal(){
  mkdsu();
  sort(edges.begin(), edges.end());
  for(const auto& e : edges){
    int u = e.second.first, v = e.second.second; ll w = (ll)e.first;
    if(find(u) != find(v)){
      Union(u, v);
      adj[u].pb(mp(v, (int)w));
      adj[v].pb(mp(u, (int)w));
    }
  }
}
 
void dfs(int u, int p, int w){
  super[u][0] = p;
  d[u][0] = w;
  dep[u] = dep[p] + 1;
  for(const pii& e : adj[u]){
    if(e.first != p) dfs(e.first, u, e.second);
  }
}
 
void precomp(){
  for(int j = 1; pow2(j)<=n; j++){
    for(int i = 1; i<=n; i++){
      super[i][j] = super[super[i][j-1]][j-1];
      d[i][j] = max(d[i][j-1], d[super[i][j-1]][j-1]);
    }
  }
}
 
ll k_up(int u, int k, int op = 0){
  ll ans = 0ll;
  for(int i = 30; ~i; i--){
    if(k&pow2(i)){
      ans = max(ans, d[u][i]);
      k -= pow2(i);
      u = super[u][i];
    }
  }
  return tern(op, ans, u);
}
 
int lca(int a, int b){
  if(dep[a] > dep[b]) swap(a, b);
  b = k_up(b, dep[b] - dep[a]);
  if(a == b) return a;
  for(int i = 30; ~i; i--){
    if(super[a][i] != super[b][i]) a = super[a][i], b = super[b][i];
  }
  orz(super[a][0] && super[a][0] == super[b][0] && a != b);
  return super[a][0];
}

void dijkstra(){
  init(dist, 0x3f);
  init(vis, 0);
  priority_queue<node> pq;
  for(int i = 1; i<=k; i++){
    dist[i] = 0;
    pq.push(node(i, 0));
  }
  while(!pq.empty()){
    node cur = pq.top(); pq.pop();
    int u = cur.u; ll w = cur.w;
    if(vis[u]) cont;
    vis[u] = 0;
    for(const pii& e : adj[u]){
      int v = e.first, te = w + (ll)e.second;
      if(dist[v] > te){
        dist[v] = te;
        pq.push(node(v, te));
      }
    }
  }
}

ll solve(int u, int v){
  int l = lca(u, v);
  ll ans = max(k_up(u, dep[u] - dep[l], 1), k_up(v, dep[v] - dep[l], 1));
  return ans;
}

signed main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m >> k >> q;
  for(int i = 0; i<m; i++){
    int a, b, c; cin >> a >> b >> c;
    adj[a].pb(mp(b, c));
    adj[b].pb(mp(a, c));
    edges.pb(mp(c, mp(a, b)));
  }
  dijkstra();
  for(int i = 0; i<m; i++){
    int u = edges[i].second.first, v = edges[i].second.second; ll w = (ll)edges[i].first;
    edges[i].first = dist[u] + dist[v] + w;
  }
  for(int i = 1; i<=n; i++) adj[i].clear();
  kruskal();
  dfs(1, 0, 0);
  precomp();
  while(q--){
    int a, b; cin >> a >> b;
    moo("%lld\n", solve(a, b));
  }
  return 0;
}


