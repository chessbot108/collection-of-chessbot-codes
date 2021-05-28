//gyrating cat enthusiast
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <utility>
//#include <cmath>
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
#define bckt(arr, val, sz) memset(arr, val, sizeof(arr[0]) * (sz))
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define tern(a, b, c) ((a) ? (b) : (c))
#define feq(a, b) (fabs(a - b) < eps)

#define moo printf
#define oom scanf
#define mool puts("") 
#define orz assert
#define fll fflush(stdout)
#define int ll
#define abs(x) tern((x) > 0ll, (x), -(x))
const lb eps = 1e-9;
const ll mod = 1e9 + 7, ll_max = (ll)1e18;
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> adj[MX];
ll l[MX], r[MX], dp[MX][3], vis[MX];
int n;

ll dfs(int u, int p, int op){
	//moo("%d %d\n", u, p);
	if(vis[u]) return dp[u][op];
	vis[u] = 1;
	
	for(int v : adj[u]){
		if(v == p) cont;
		dp[u][0] += max(dfs(v, u, 1) + (ll)abs(l[u] - r[v]), dfs(v, u, 0) + (ll)abs(l[u] - l[v]));
		dp[u][1] += max(dfs(v, u, 1) + (ll)abs(r[u] - r[v]), dfs(v, u, 0) + (ll)abs(r[u] - l[v]));
	}
	//moo("%d %d, %lld %lld\n", u, p, dp[u][0], dp[u][1]);
	return dp[u][op]; //my brain is tiny!!!!!!
}

signed main(){
  cin.tie(0) -> sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		cin >> n; 
		for(int i = 0; i<=n+4; i++) dp[i][0] = dp[i][1] = 0ll;
		bckt(vis, 0, n + 2);
		//n = 3e3;
		for(int i = 1; i<=n; i++){
			cin >> l[i] >> r[i];
			//l[i] = 0, r[i] = 1e9;
		}
		for(int i = 1; i<=n; i++) adj[i].clear(); //im dumb in the head	
		for(int i = 1; i<n; i++){
			int a, b; cin >> a >> b;
			//a = i, b = i+1;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		moo("%lld\n", max(dfs(1, 0, 1), dfs(1, 0, 0)));
	}		
  return 0;
}


