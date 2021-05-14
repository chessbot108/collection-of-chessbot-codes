//here take a cat
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
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ins insert
#define cont continue
#define pow2(n) (1 << (n))

#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define bckt(arr, val, sz) memset(arr, val, sizeof(arr[0]) * (sz))
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define tern(a, b, c) ((a) ? (b) : (c))
#define feq(a, b) (fabs(a - b) < eps)

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


vector<pii> adj[MX];
vector<pair<int, pii>> edges, query;
int par[MX], super[MX][40], d[MX][40], dep[MX];
int n, m;
int find(int x){ if(x != par[x]) par[x] = find(par[x]); return par[x]; }
void Union(int a, int b){ a = find(a), b = find(b); par[a] = b; }

void mkdsu(){ for(int i = 0; i<=n; i++) par[i] = i; }

ll kruskal(){
  mkdsu();
  sort(edges.begin(), edges.end());
  ll ans = 0ll;
  for(const auto& e : edges){
    int u = e.second.first, v = e.second.second; ll w = (ll)e.first;
    if(find(u) != find(v)){
      ans += w;
      Union(u, v);
      adj[u].pb(mp(v, (int)w));
      adj[v].pb(mp(u, (int)w));
    }
  }
  return ans;
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

int k_up(int u, int k, int op = 0){
  int ans = 0;
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

int solve(int u, int v, int w){
  int l = lca(u, v);
  int ans = max(k_up(u, dep[u] - dep[l], 1), k_up(v, dep[v] - dep[l], 1));
  orz(ans <= w);
  return w-ans;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 0; i<m; i++){
    int a, b, c; cin >> a >> b >> c;
    auto e = mp(c, mp(a, b));
    edges.pb(e); query.pb(e);
  }
  ll mst = kruskal();
  dfs(1, 0, 0);
  precomp();
  for(const auto& e : query){ 
    int u = e.second.first, v = e.second.second, w = (ll)e.first;
    moo("%lld\n", mst + (ll)solve(u, v, w));
  }
  return 0;
}


