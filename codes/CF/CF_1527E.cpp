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
const int MX = 4e4 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll mnn[MX *4], add[MX*4], arr[MX], last[MX];
ll dp[MX][200];

int n, k, s = 1;

void build(int j){
	init(mnn, 63);
	init(add, 0);
	for(int i = s - 1; i < s + n; i++){
		mnn[i] = dp[i - (s - 1)][j];
	}
	for(int i = s - 2; ~i; i--){
		mnn[i] = min(mnn[LC(i)], mnn[RC(i)]);
	}
}

void U(int qL, int qR, int k, ll v, int L, int R){
	if(qR <= L || R <= qL || R <= L) return ;
	if(qL <= L && R <= qR){
		add[k] += v;
		return ;
	}
	int mid = (L + R)/2;
	U(qL, qR, LC(k), v, L, mid);
	U(qL, qR, RC(k), v, mid, R);
	mnn[k] = min(mnn[LC(k)] + add[LC(k)], mnn[RC(k)] + add[RC(k)]);
}

ll Q(int qL, int qR, int k, int L, int R){
	if(qR <= L || R <= qL || R <= L) return int_max;
	if(qL <= L && R <= qR) return add[k] + mnn[k];
	int mid = (L + R)/2;
	return add[k] + min(Q(qL, qR, LC(k), L, mid), Q(qL, qR, RC(k), mid, R));
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> k;
	while(s<=n) s *= 2;
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	init(dp, 63); //blobcosy
	dp[0][0] = 0;
	build(0);
	for(int j = 1; j<=k; j++){
		init(last, 0xBF);
		for(int i = 1; i<=n; i++){
			if(last[arr[i]] >= 0){
				U(0, last[arr[i]], 0, i - last[arr[i]], 0, s);
				//telescoping
			}
			last[arr[i]] = i;
			dp[i][j] = Q(0, i, 0, 0, s);
		}
		build(j);
	}
	cout << dp[n][k] << "\n";
  return 0;
}


