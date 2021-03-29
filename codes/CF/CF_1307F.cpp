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
const int MX = 5e5 +10, int_max = 0x3f3f3f3f, LOGN = 30;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int DSU[MX], rest[MX], dist[MX], vis[MX];
int super[MX][LOGN], dep[MX];
int n, K, r, q;

vector<int> adj[MX];

int find(int x){ if(x != DSU[x]) DSU[x] = find(DSU[x]); return DSU[x]; }
void Union(int a, int b){ DSU[find(a)] = find(b); }
void mkdsu(){ for(int i = 0; i<=n*2 +3; i++) DSU[i] = i; }

void bfs(){
  queue<int> q;
  init(dist, 0x3f);
  for(int i = 0; i<r; i++){
    q.push(rest[i]);
    dist[rest[i]] = 0;
  }

  while(q.size()){
    int u = q.front(); q.pop();
    if(dist[u] > K - 1) break;
    if(vis[u]) cont;
    //moo("\n\tbfs to %d with dist %d\n", u, dist[u]);
    vis[u] = 1;
    for(int v : adj[u]){
      //moo("\t\t%d ", v);
      Union(u, v);
      if(dist[v] == int_max){
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }   
  
}

void dfs(int u, int p){
  dep[u] = dep[p] + 1;
  super[u][0] = p;
  for(int v : adj[u]){
    if(v != p) dfs(v, u);
  }
}

void precomp(){
  for(int j = 1; j <= 28; j++){
    for(int i = 1; i<=n; i++){
      super[i][j] = super[super[i][j - 1]][j - 1];
    }
  }
}

int k_up(int u, int k){
  assert(dep[u] >= k);
  for(int j = 28; ~j; j--){
    if(k >= pow2(j)) k = k - pow2(j), u = super[u][j];
  }
  return u;
}

int lca(int a, int b){
  if(dep[a] < dep[b]) swap(a, b);
  a = k_up(a, dep[a] - dep[b]);
  if(a == b) return a;
  for(int j = 28; ~j; j--){
    if(super[a][j] != super[b][j]) a = super[a][j], b = super[b][j];
  }
  assert(a != b); assert(a); assert(super[a][0] == super[b][0]);
  return super[a][0];
}

int walk(int a, int b, int s){//want a towards b k steps
  int l = lca(a, b);
  //moo("lca(%d %d) == %d\n", a, b, l);
  if(s <= dep[a] - dep[l]) return k_up(a, s);
  int d = s - (dep[a] - dep[l]);
  assert(s <= dep[b] - dep[l]);
  return k_up(b, (dep[b] - dep[l]) - d);
}

int Q(int a, int b){
  int l = lca(a, b);
  if(dep[a] + dep[b] - (dep[l]*2) <= 2*K) return 1;
  else return (find(walk(a, b, K)) == find(walk(b, a, K)));
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> K >> r;
  for(int i = 1; i<n; i++){
    int a, b, c = i + n + 1; cin >> a >> b;
    adj[a].pb(c);
    adj[b].pb(c);
    adj[c].pb(a);
    adj[c].pb(b);
    //moo("edge: %d - %d - %d\n", a, c, b);
  }   
  for(int i = 0; i<r; i++){
    cin >> rest[i];
  }  
  mkdsu();
  bfs();
  dfs(1, 0);
  precomp();
  cin >> q;
  while(q--){
    int a, b; cin >> a >> b;
    //moo("%d\n", lca(a, b));
    moo("%s\n", tern(Q(a, b), "YES", "NO"));
    //moo("a -> %d, b -> %d\n", a, b);
    //walk(a, b, K); walk(b, a, K);
    //moo("a -> b: %d\nb -> a: %d\n", walk(a, b, K), walk(b, a, K));
  }
	return 0;
}


