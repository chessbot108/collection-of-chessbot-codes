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
const ll mod = 1e9 + 7, MOD = 1e9 + 7, ll_max = (ll)1e18;
const int MX = 2e2 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//purple why speedforces :<

//benq modint
struct mi {
 	int v; explicit operator int() const { return v; } 
	mi() { v = 0; }
	mi(ll _v):v(_v%MOD) { v += (v<0)*MOD; }
};
mi& operator+=(mi& a, mi b) { 
	if ((a.v += b.v) >= MOD) a.v -= MOD; 
	return a; }
mi& operator-=(mi& a, mi b) { 
	if ((a.v -= b.v) < 0) a.v += MOD; 
	return a; }
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((ll)a.v*b.v); }
mi& operator*=(mi& a, mi b) { return a = a*b; }
mi pow(mi a, ll p) { assert(p >= 0); // asserts are important! 
	return p==0?1:pow(a*a,p/2)*(p&1?a:1); }
mi inv(mi a) { assert(a.v != 0); return pow(a,MOD-2); }
mi operator/(mi a, mi b) { return a*inv(b); }


int n, sub[MX], dep[MX], par[MX];
vector<int> adj[MX];

mi dp[MX][MX], sz[MX], psum[MX], chi[MX];
//probability i is reachable in j steps AND NO SOONER
//expected number of nodes availible after i steps

int dfs1(int u, int p){
	dep[u] = dep[p] + 1;
	par[u] = p;
	for(int v : adj[u]){
		if(v != p) sub[u] += dfs1(v, u);
	}
	return 1;
}


mi solve(int u){
	init(dep, 0);
	init(sub, 0);
	dfs1(u, 0);
	for(int i = 0; i<=n; i++){
		for(int j = 0; j<=n; j++){
			dp[i][j] = mi();
		}
	}
	for(int i = 0; i<=n; i++) dp[u][i] = mi(1);
	
	for(int j = 1; j<=n; j++){
		for(int i = 1; i<=n; i++){
			sz[j] += dp[i][j-1]*chi[i];
			chi[i] = mi();
		}
		for(int i = 1; i<=n; i++){
			dp[i][j] = dp[par[i]][j-1]/sz[j];
			if(i != u) chi[par[i]] += dp[i][j]/sub[par[i]];
			if(i > u) psum[j] += dp[i][j];
		}
	}
	mi ans(0);
	for(int j = 1; j<=n; j++){
		psum[j] += psum[j-1];
		ans += psum[j];
	}
	return ans;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	mi ans(0);
	for(int i = 1; i<=n; i++){
		ans += solve(i)/mi(n);
	}
	moo("%lld\n", ans);
  return 0;
}


