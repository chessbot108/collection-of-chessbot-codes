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
#define C(a, b) ((fac[(a)] * ((inv[(b)] * inv[(a) - (b)])%mod))%mod)

#define moo printf
#define oom scanf
#define mool puts("") 
#define orz assert
#define fll fflush(stdout)

const lb eps = 1e-9;
const ll mod = 1e9 + 7, ll_max = (ll)1e18;
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll dp[MX], fac[MX], inv[MX];
vector<pii> ve;
int n, h, w;

ll Pow(ll a, ll b){
	ll ans = 1;
	for(ll i = 1; i<=b; i*=2ll){
		if(b&i) (ans *= a) %= mod;
		(a *= a) %= mod;
	}	
	return ans;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
	fac[0] = inv[0] = 1;
	for(int i = 1; i<=2e5; i++){
		(fac[i] = fac[i-1]*(ll)i) %= mod;
		inv[i] = Pow(fac[i], mod-2);
	}
	cin >> h >> w >> n;
	for(int i = 0; i<n; i++){
		int a, b; cin >> a >> b;
		ve.pb(mp(a, b));
	}
	ve.pb(mp(h, w));
	orz(n+1 == siz(ve));
	sort(ve.begin(), ve.end());
	for(int i = 0; i<=n; i++){
		dp[i] = C(ve[i].first + ve[i].second-2, ve[i].first-1);
		for(int j = 0; j<i; j++){
			if(ve[j].first <= ve[i].first && ve[j].second <= ve[i].second){
				//moo("%d {%d %d} %d {%d %d}, %d %d\n", i, ve[i].first, ve[i].second, j, ve[j].first, ve[j].second, ve[i].first - ve[j].first, ve[i].second - ve[j].second);
				dp[i] += mod - ((dp[j] * C(ve[i].first + ve[i].second - (ve[j].first + ve[j].second), ve[i].first - ve[j].first))%mod);
			}
		}
		dp[i] %= mod;
	}
	moo("%lld\n", dp[n]);
  return 0;
}


