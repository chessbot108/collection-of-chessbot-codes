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

const ll mod = 1e9 + 7;
const int MX = 2e3 +10, int_max = 0x3f3f3f3f;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}
int dist[MX][MX], n, par[MX], sz[MX];
vector<pii> adj[MX];
vector<pair<int, pii>> edges;

int find(int x){
  if(x != par[x]) par[x] = find(par[x]); 
  return par[x];
}

void Union(int a, int b){
  a = find(a), b = find(b);
  if(a == b) return ;
  if(sz[a] > sz[b]) swap(a, b);
  par[b] = a;
  sz[a] += sz[b];
}
  
void mkdsu(){
  for(int i = 0; i<=n; i++){
    par[i] = i, sz[i] = 1;
  }
}

bool cmp(const pair<int, pii> &a, const pair<int, pii>& b){
  return a.first < b.first;
}

void kruskals(){
  int tot = 0;
  mkdsu();
  sort(edges.begin(), edges.end(), cmp);
  for(const auto& e : edges){
    if(tot == n) break;
    int u = e.second.first, v = e.second.second, w = e.first;
    if(find(u) != find(v)){
      //cout << u << " " << v << " " << w << endl;
      Union(u, v);
      tot = max(tot, sz[find(u)]);
      adj[u].pb(mp(v, w));
      adj[v].pb(mp(u, w));
    }
  }
}

bool dfs(int u, int p, int src, int d){
  if(dist[src][u] != d || (src != u && dist[src][u] == 0)) return false;
  bool ans = 1;
  for(const auto& e : adj[u]){
    if(e.first == p) cont;
    ans &= dfs(e.first, u, src, d + e.second);
  }
  return ans;
}



int main(){
	cin.tie(0) -> sync_with_stdio(0);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  bool ans = 1;
  cin >> n;
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n; j++){
      cin >> dist[i][j];
      if(i != j){
        if(j < i && dist[i][j] != dist[j][i]) ans = 0; 
        if(i < j) edges.pb(mp(dist[i][j], mp(i, j)));
      }else{
        if(dist[i][j] != 0) ans = 0;
      }
    }
  }
  
  kruskals();
  
  for(int i = 1; i<=n; i++){
    ans &= dfs(i, 0, i, 0);
  }
  if(ans) cout << "YES\n";
  else cout << "NO\n";
  
	return 0;
}


