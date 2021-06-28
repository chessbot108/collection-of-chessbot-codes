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
const ll mod = 1e9 + 7, ll_max = (ll)1e18;
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int even[] = {20, 19, 18, 16, 5, 1};
int odd[] = {20, 19, 18, 16, 4};
ll arr[30];


void brute(int n, int k){
	for(int i = 0; i<n; i++) cin >> arr[i];
	ll tot1 = 1e15, tot2 = 0;
	for(int i = 0; i<(1 << n); i++){
		ll t = 0,s = 0;
		for(int j = 0; j<n; j++) if(i&(1 << j)) s += arr[j]; else t += arr[j];
		tot1 = min(tot1, abs(s - t));
	}
	sort(arr, arr + n);
	ll s = 0, t = 0;
	for(int i = 0; i<n; i++){
		if(s < t) s += arr[i];
		else t += arr[i];
	}
	tot2 = abs(s - t);
	moo("%d, %d, %lld, %lld\n", n, k, tot1, tot2);
}



int main(){
  cin.tie(0) -> sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		ll n, k; cin >> n >> k;
		//brute(n, k); cont;
		ll buf = 1e5;
		if(n <= 4){
			puts("-1");
			cont;
		}
		if(n%2){
			assert(n >= 5); n -= 5;
			for(int i = 0; i<5; i++) moo("%lld ", (ll)odd[i] * k);
			while(n--) moo("%lld ", buf * k);
			mool;
		}else{
			assert(n >= 6); n -= 6;
			for(int i = 0; i<6; i++) moo("%lld ", (ll)even[i] * k);
			while(n--) moo("%lld ", buf * k);
			mool;
		}
	}
  return 0;
}


