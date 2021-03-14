#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
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
#define init(arr, val) memset(arr, val, sizeof(arr))
//geniousity limit exceeded
#define moo printf
#define oom scanf
const ll mod = 1e9 + 7;
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int super[MX][30], dep[MX], trav[MX], psums[MX], ans[MX];
int n, q, ind;
vector<int> adj[MX];
void dfs(int u, int p, int d){
  super[u][0] = p;
  dep[u] = d;
  for(int v : adj[u]){
    if(v != p)
      dfs(v, u, d + 1);
  }
  trav[ind++] = u;
} 

void precomp(){
  for(int j = 1; pow2(j) <= n; j++){
    for(int i = 1; i<=n; i++){
      super[i][j] = super[super[i][j - 1]][j - 1];
    }
  }
}

int k_up(int u, int k){
  for(int i = 28; ~i; i--){
    if(pow2(i) <= k) k = k - pow2(i), u = super[u][i];
  }
  return u;
}

int lca(int a, int b){
  if(dep[a] > dep[b]) swap(a, b);
  b = k_up(b, dep[b] - dep[a]);
  if(a == b) return a;
  for(int j = 27; ~j; j--){
    if(super[a][j]^super[b][j]) a = super[a][j], b = super[b][j];
  }
  assert(super[a][0] != 0 && super[a][0] == super[b][0]);
  return super[a][0];
}



int main(){
  cin.tie(0) -> sync_with_stdio(0);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  oom("%d%d", &n, &q);
  for(int i = 1; i<n; i++){
    int a, b; oom("%d%d", &a, &b);
    adj[a].pb(b);
    adj[b].pb(a);
  }
  dfs(1, 0, 0);
  precomp();
  while(q--){
    int a, b; oom("%d%d", &a, &b);
    int l = lca(a, b), p = super[l][0];
    psums[a]++;
    psums[b]++;
    psums[l]--;
    psums[p]--;
  }
  for(int t = 0; t<n; t++){
    int u = trav[t];
    ans[u] = psums[u];
    for(int v : adj[u]){
      if(v != super[u][0]) ans[u] += ans[v];
    }
  }
  for(int i = 1; i<=n; i++){
    moo("%d ", ans[i]);
  }
  puts("");
	return 0;
}


