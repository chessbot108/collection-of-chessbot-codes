#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>

#define max_v 110000
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

int super[max_v * 2][30], cen[max_v], best[max_v], sub[max_v], dep[max_v], col[max_v], vis[max_v];
int n, q;
vector<int> adj[max_v];
//CD start
int getsz(int u, int p){
  if(vis[u]) return 0;
  sub[u] = 0;
  for(int v : adj[u]){
    if(v != p){
      sub[u] += getsz(v, u);
    }
  }
  return ++sub[u];
}

int find_cen(int u, int p, int sz){
  for(int v : adj[u]){
    if(v != p && sub[v] > sz/2 && !vis[v]){ //parent check might not be needed. 
      return find_cen(v, u, sz); //guarantee logn
    }
  }
  return u;
}

void mktree(int u, int p){
  if(vis[u]) return ;
  int C = find_cen(u, 0, getsz(u, 0));
  vis[C] = 1;
  cen[C] = p;
  for(int v : adj[C]){
    if(!vis[v]) mktree(v, C);
  }
}
//CD end

//LCA start
void dfs(int u, int p, int d){
  //cout << u << " " << p << " " << d << endl;
  super[u][0] = p;
  dep[u] = d;
  for(int v : adj[u]){

    if(v != p){
      dfs(v, u, d + 1);
    }
  }
}

void precomp(){
  dfs(1, 0, 0); //rooting is arbitrary, just need distances
  //cout << "dfs done" << endl;
  for(int j = 1; pow_2(j) <= n; j++){
    for(int i = 1; i<=n; i++){
      super[i][j] = super[super[i][j - 1]][j - 1];
    }
  }
}

int k_up(int u, int k){
  for(int j = 20; j >= 0; j--){
    if(pow_2(j) <= k) k = k - pow_2(j), u = super[u][j];
  }
  assert(u != 0 && k == 0);
  return u;
}

int lca(int u, int v){
  if(dep[u] > dep[v]) swap(u, v);
  v = k_up(v, dep[v] - dep[u]);
  if(u == v) return u;
  assert(dep[u] == dep[v]);
  for(int j = 20; j>=0; j--){
    if(super[u][j] != super[v][j]) u = super[u][j], v = super[v][j];
  }
  assert(super[u][0] == super[v][0]);
  return super[u][0];
}

int dist(int u, int v){
  int l = lca(u, v);
  return dep[u] + dep[v] - (dep[l] + dep[l]);
}
//LCA end
//just oing to pray i didnt butcher the impl's

//problem specific

void U(int u){
  if(col[u]) return ;
  col[u] = 1;
  for(int p = u; p; p = cen[p]){
    best[p] = min(best[p], dist(u, p));
  }
}

int Q(int u){
  int ans = int_max;
  for(int p = u; p; p = cen[p]){
    ans = min(ans, best[p] + dist(u, p));
  }
  return ans;
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> q;
  for(int i = 1; i<n; i++){
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  } 
  precomp();
  mktree(1, 0);
  memset(best, 60, sizeof(best));
  U(1);
  while(q--){
    int op, u;
    cin >> op >> u;
    if(op == 1){
      U(u);
    }else{
      cout << Q(u) << '\n';
    }
  }
	return 0;
}


