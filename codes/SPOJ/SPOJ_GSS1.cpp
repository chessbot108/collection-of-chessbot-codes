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
const int MX = 4e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll sum[MX], ab[MX], bc[MX], abc[MX], arr[MX];
int n, q, s = 1;

int li[50], ind = 0;

void Q(int qL, int qR, int k, int L, int R){
	if(qR <= L || R <= qL || R <= L) return ;
	if(qL <= L && R <= qR){
		li[ind++] = k;
		return ;
	}
	int mid = (L + R)/2;
	Q(qL, qR, LC(k), L, mid);
	Q(qL, qR, RC(k), mid, R);
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
	cin >> n;
	while(s < n) s *= 2;
	for(int i = 0; i<n; i++) cin >> arr[i];
	for(int i = s - 1; i < s*2; i++){
		sum[i] = abc[i] = ab[i] = bc[i] = tern((i >= (s + n - 1)), -1e18, arr[i-(s - 1)]);
	}
	for(int i = s - 2; ~i; i--){
		sum[i] = sum[LC(i)] + sum[RC(i)];
		ab[i] = max({ab[LC(i)], sum[LC(i)] + ab[RC(i)]});
		bc[i] = max({bc[RC(i)], sum[RC(i)] + bc[LC(i)]});
		abc[i] = max({bc[LC(i)] + ab[RC(i)], abc[LC(i)], abc[RC(i)]});
	}
	cin >> q;
	while(q--){
		int a, b; cin >> a >> b;
		a--; ind = 0;//convert to 0 based exlucsive
		Q(a, b, 0, 0, s);
		ll pre = -1e18, ans = -1e18;
		for(int i = 0; i<ind; i++){ //just run kadanes
			int k = li[i];
			ans = max({ans, abc[k], pre + ab[k]}); 
			//current answer, block answer, suffix + prefix
			pre = max(pre + sum[k], bc[k]);
		}
		moo("%lld\n", ans);
	}
  return 0;
}


