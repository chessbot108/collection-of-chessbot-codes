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


struct node{
  int u, w;
  node(){};
  node(int a, int b){ u=a, w=b; }
  bool operator < (const node& b) const{
    return w < b.w; //HMMMM
  }
};

int dep[MX], dist[MX][5], vis[MX], par[MX], deg[MX];
int n;
priority_queue<node> pq;
vector<int> adj[MX];
vector<pair<pii, int>> ans;
void dfs(int u, int p, int d, int op){
  par[u] = p;
  dep[u] = d;
  dist[u][op] = max(d, dist[u][op]);
  for(int v : adj[u]){
    if(v != p) dfs(v, u, d + 1, op);
  }
}

void mark(int x){
  if(!x || vis[x]) return ;
  vis[x] = 1;
  mark(par[x]);
}

int far(int x, int op){
  dfs(x, 0, 0, op);
  for(int i = 1; i<=n; i++){
    if(dep[i] > dep[x]) x = i;
  }
  return x;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i<n-1; i++){
    int a, b; cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  int d1 = far(1, 0), d2 = far(d1, 1); far(d2, 2);
  mark(d1); mark(d2);
  for(int i = 1; i<=n; i++){
    deg[i] = adj[i].size();
    if(deg[i] == 1) pq.push(node(i, max(dist[i][1], dist[i][2])));
  }
  ll res = 0ll;
  while(!pq.empty()){
    node cur = pq.top(); pq.pop();
    int u = cur.u, w = cur.w, v = tern(dist[u][1] > dist[u][2], d1, d2), p = par[u];
    if(vis[u]) cont;
    ans.pb(mp(mp(u, v), u));
    res += w;
    deg[p]--;
    if(deg[p] == 1){
      pq.push(node(p, max(dist[p][1], dist[p][2])));
    }
  }
  for(; d1 != d2; d1 = par[d1]){
    ans.pb(mp(mp(d1, d2), d1));
    res += (ll)dep[d1];
  }
  moo("%lld\n", res);
  for(const auto& e : ans){
    moo("%d %d %d\n", e.first.first, e.first.second, e.second);
  }
  return 0;
}


