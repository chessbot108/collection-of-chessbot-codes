//gyrating cat enthusiast
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

const lb eps = 1e-9;
const ll mod = 998244353, ll_max = (ll)1e18;
const int MX = 1e6 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

//dp[i] = sum(dp[1...i] + factors of i)
//1. [ - dp[i-1] - ], [[ - dp[i-2] - ]], ...
//i cant do ascii art in 3d :<

ll vis[MX], dp[MX], low[MX], fac[MX]; //imagine knowing how to seive properly
int temp[20]; 
set<int> s; //tle here we come. wheeeeeeeee

int main(){
  cin.tie(0) -> sync_with_stdio(0);
	int n; cin >> n;
	for(int i = 2; i<=n; i++){
		fac[i]++; //count 1
		for(int j = i; j<=n; j+=i){
			fac[j]++;
		}	
	}
	ll sum = 1; dp[1] = 1;
	for(int i = 2; i<=n; i++){
		dp[i] = (sum + (ll)fac[i])%mod;
		(sum += dp[i]) %= mod; //pray no wa
	}
	moo("%lld\n", dp[n]);
  return 0;
}


