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
const int MX = 1e6 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int sum[4*MX], arr[MX];
int n, q, s = 1;
void U(int k, int val){
	k = s + k - 1;
	while(1){
		//moo("%d %d %d\n", k, val, sum[k]);
		sum[k] += val;
		if(!k) break;
		k = (k - 1)/2;
	}
}

int S(int kth, int k, int L, int R){
	if(L + 1 == R) return L;
	int mid = (L + R)/2, dist = sum[LC(k)];
	if(kth > dist) return S(kth - dist, RC(k), mid, R);
	return S(kth, LC(k), L, mid);
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> q;
	while(s<=n) s *= 2;
	for(int i = 0; i<n; i++){
		cin >> arr[i];
		sum[arr[i] + s - 1]++;
	}
	for(int i = s - 1; ~i; i--) sum[i] = sum[LC(i)] + sum[RC(i)];
	while(q--){
		int k; cin >> k;
		int u = tern(k < 0, S(abs(k), 0, 0, s), k);
		U(u, k/abs(k));
		//cout << sum[0] << endl;
	}
	moo("%d\n", tern(sum[0], S(1, 0, 0, s), 0));	
  return 0;
}


