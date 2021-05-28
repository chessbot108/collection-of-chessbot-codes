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

ll st[MX*4], dp[MX], arr[MX], add[MX*4];

ll S(int k){
	return st[k] + add[k];
}

void U(int qL, int qR, ll val, int k, int L, int R){
	if(qR <= L || R <= qL || R <= L) return ;
	if(qL <= L && R <= qR) add[k] += val;
	int mid = (L + R)/2;
	U(qL, qR, val, LC(k), L, mid);
	U(qL, qR, val, RC(k), mid, R);
	st[k] = max(S(LC(k)), S(RC(k)));
}

void Q(int qL, int qR, int k, int L, int R){
`
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);

  return 0;
}


