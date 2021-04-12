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
const int MX = 1e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}
int super[MX][30], dep[MX], sub[MX], par[MX];
int n, q;

vector<int> adj[MX];

int dfs(int u, int p, int d){
  par[u] = super[u][0] = p;
  dep[u] = d;
  for(int v : adj[u]){
    if(v == p) cont;
    sub[u] += dfs(v, u, d + 1);
  }
  return ++sub[u];
}

void precomp(){
  for(int j = 1; pow2(j)<=n; j++){
    for(int i = 1; i<=n; i++){
      super[i][j] = super[super[i][j - 1]][j - 1];
    }
  }
}

int k_up(int u, int k){
  for(int i = 24; ~i; i--){
    if(k&pow2(i)) k = k - pow2(i), u = super[u][i];
  }
  assert(u);
  return u;
}

int lca(int a, int b){
  if(dep[a] < dep[b]) swap(a, b);
  a = k_up(a, dep[a] - dep[b]);
  if(a == b) return a;
  for(int i = 24; ~i; i--){
    if(super[a][i] != super[b][i]) a = super[a][i], b = super[b][i];
  }
  assert(par[a] == par[b] && a && a != b);
  return par[a];
} 

int dist(int a, int b){
  return dep[a] + dep[b] - (dep[lca(a, b)] * 2);
}

int Q(int a, int b){
  int l = lca(a, b);
  int d = dist(a, b);
  if(d%2 == 1) return 0;
  if(a == b) return n;
  if(dep[a] < dep[b]) swap(a, b);
  int mid = k_up(a, d/2);
  assert(dist(mid, b) == d/2 && dist(mid, a) == dist(mid, b));
  int s = k_up(a, d/2 -1);
  if(mid == l){
    int p = k_up(b, d/2 -1);
    return (n - sub[l]) + sub[l] - (sub[p] + sub[s]);
  }else{
    return sub[mid] - sub[s];
  }
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i<n; i++){
    int a, b; cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  dfs(1, 0, 0);
  precomp();
  cin >> q;
  while(q--){
    int a, b; cin >> a >> b;
    moo("%d\n", Q(a, b));
  }
	return 0;
}


