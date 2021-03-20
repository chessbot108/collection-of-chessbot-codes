#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>

#define cont continue
#define pow2(n) (1 << (n))
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define init(arr, val, sz) memset(arr, val, sizeof(arr[0]) * (sz))
//geniousity limit exceeded
#define moo printf
#define oom scanf
const ll mod = 1e9 + 7;
const int MX = 1e5 +10, int_max = 0x3f3f3f3f;
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

vector<int> adj[MX], adj2[MX];
int n, m, vis[MX], pre[MX], par[MX], dep[MX]; //going to find bridge edges and bridge nodes

void dfs(int u, int p, int d){
  //moo("dfs: %d %d\n", u, p);
  vis[u] = 1;
  par[u] = p;
  dep[u] = d;
  for(int v : adj[u]){
    if(v == p) cont;
    if(vis[v]){
      //moo("%d -> %d is a back edge\n", v, u);
      if(dep[u] > dep[v]) pre[u]++, pre[v]--;
    }else{
      adj2[u].pb(v);
      adj2[v].pb(u);
      dfs(v, u, d + 1);
    }
  }
}

void gpre(int u){
  //moo("dfs2: %d\n", u);
  for(int v : adj2[u]){
    if(v == par[u]) cont;
    gpre(v);
    pre[u] += pre[v];
  }
  if(u == 1) pre[u] = 1; //jokes on you, node 1 never gets a back edge. i actually dont know how to handle this edge case
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 0; i<m; i++){
    int a, b; cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  dfs(1, 0, 0);
  gpre(1);
  //for(int i = 1; i<=n; i++) moo("%d -> %d\n", i, pre[i]); puts("");
  int k = 0; 
  for(int i = 1; i<=n; i++) if(!pre[i]) k++;
  moo("%d\n", k);
  for(int i = 1; i<=n; i++) if(!pre[i]) moo("%d %d\n", i, par[i]); puts("");
	return 0;
}


