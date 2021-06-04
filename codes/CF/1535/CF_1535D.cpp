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
const int MX = 3e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//segtree 

int sum[MX * 4], n, q, s = 1;
char str[MX];

void U(int i){
	while(1){
		//moo("%d\n", i);
		sum[i] = tern((i >= s - 1) && (i < s*2 -1), 1, tern(str[i] == '?', sum[LC(i)] + sum[RC(i)], tern(str[i] == '1', sum[LC(i)], sum[RC(i)])));
		i = (i - 1);
		if(i == -1) break;
		i /= 2;
	}
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
	oom("%d%s", &s, str);
	//s = 18; bckt(str, '?', (1 << s) -6);
	s = (1 << s);
	n = strlen(str);
	assert(n == s-1);
	reverse(str, str + n);
	for(int i = s - 1; i<s*2 -1; i++){
		sum[i] = 1;
	}
	for(int i = s - 2; ~i; i--){
		//moo("%d %d %c\n", i, sum[i], str[i]);
		sum[i] = tern(str[i] == '?', sum[LC(i)] + sum[RC(i)], tern(str[i] == '1', sum[LC(i)], sum[RC(i)]));
	}
	//moo("wtmoo\n");
	oom("%d", &q);
	while(q--){
		int a; char b[3];
		oom("%d%s", &a, b);
		a = (s - a) - 1;
		str[a] = b[0];
		//moo("%s\n", str);
		U(a);
		moo("%d\n", sum[0]);
	}
  return 0;
}


