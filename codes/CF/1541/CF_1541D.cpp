//gyrating cat enthusiast
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <utility>
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
#define siz(vec) ((int)(vec.size()))

#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define bckt(arr, val, sz) memset(arr, val, sizeof(arr[0]) * (sz+5))
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define tern(a, b, c) ((a) ? (b) : (c))
#define feq(a, b) (fabs(a - b) < eps)
#define abs(x) tern((x) > 0, x, -(x))

#define moo printf
#define oom scanf
#define mool puts("") 
#define orz assert
#define fll fflush(stdout)

const lb eps = 1e-9;
const ll mod = 1e9 + 7, i2 = (mod+1)/2, ll_max = (ll)1e18;
const int MX = 2e2 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll dp[MX][MX], lca[MX][MX];
int dep[MX], par[MX], trav[MX], vis[MX];
vector<int> adj[MX];

ll Pow(ll a, ll k){
	ll ans = 1;
	for(ll i = 1; i<=k; i*=2){
		if(k&i) (ans *= a) %= mod;
		(a *= a) %= mod;
	}
	return ans;
}	

void dfs(int u, int p){
	dep[u] = dep[p]+1;
	par[u] = p;
	for(int v : adj[u]){
		if(v != p) dfs(v, u);
	}
}

int find(int x, int s){
	if(!vis[x]){
		lca[s][x] = find(par[x], s);
		vis[x] = 1;
	}	
	return lca[s][x];
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
	int n; cin >> n;
	for(int i = 0; i<n-1; i++){
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for(int i = 0; i<=n; i++) dp[0][i] = 1;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			(dp[i][j] = (dp[i-1][j]+dp[i][j-1])*i2) %= mod;
		}
	}	
	ll tot = 0;
	for(int i = 1; i<=n; i++){
		dfs(i, 0);
		for(int j = 1; j<=n; j++){
			init(vis, 0);
			for(int k = j; k; k = par[k]){
				vis[k] = 1; lca[j][k] = k;
			}
			for(int k = 1; k<=n; k++){
				if(!vis[k]) find(k, j);
			}		
		}	
		//for(int j = 1; j<=n; j++){
			//for(int k = 1; k<=n; k++){
				//moo("%3d", lca[j][k]);
			//} mool;
		//}
		for(int j = 1; j<=n; j++){
			for(int k = j+1; k<=n; k++){
				if(j == k) cont;
				int l = lca[j][k], d = dep[l];
				tot += dp[dep[k] - d][dep[j] - d];
				tot %= mod;
			}
		}
	}
	moo("%lld\n", (tot*Pow(n, mod-2))%mod);
  return 0;
}


