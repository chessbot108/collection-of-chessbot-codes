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
ll dp[MX][30]; //color branch i with color j
vector<int> adj[MX];
int ban[MX][30], vis[MX][30];
int n, m;

ll dfs(int u, int p, int col){
  if(vis[u][col]) return dp[u][col];
  dp[u][col] = 1ll;
  vis[u][col] = 1;
  for(int v : adj[u]){
    if(v == p) cont;
    ll temp = 0ll;
    for(int c = 1; c<=m; c++){
      if(ban[u][c] || ban[v][col]) cont;
      temp = add(temp, dfs(v, u, c));
    }
    dp[u][col] = mul(dp[u][col], temp);
  }
  return dp[u][col];
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 0; i<n - 1; i++){
    int a, b; cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  for(int i = 1; i<=n; i++){
    int k; cin >> k;
    while(k--){
      int a; cin >> a;
      ban[i][a] = 1;
    }
  }
  ll tot = 0ll;
  for(int i = 1; i<=m; i++){
    tot = add(tot, dfs(1, 0, i));
  }
  moo("%lld\n", tot);
	return 0;
}


