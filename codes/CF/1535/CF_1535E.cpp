//i give up, will upsolve later


//gyrating cat enthusiast
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
//does it help?

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

int a[MX], c[MX], par[MX], super[MX][40];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int q;	
	cin >> q >> a[0] >> c[0];
	for(int i = 1; i<=q; i++){
		int op; cin >> op;
		if(op == 1){
			cin >> par[i] >> a[i] >> c[i];
			super[i][0] = par[i];
			for(int j = 1; (1 << j) <= q; j++) super[i][j] = super[super[i][j-1]][j-1];
		}else{
			int u, w; cin >> u >> w;
			ll weight = 0, cost = 0;
			while(w > 0 && a[u] > 0){
				int v = u;
				for(int k = 20; ~k; k--){
					if(a[super[v][k]] > 0){
						v = super[v][k];
					}
				}
				int t = min(w, a[v]);
				a[v] -= t; w -= t;
				weight += t;
				cost += (ll)t * (ll)c[v];
			}
			cout << weight << " " << cost << endl;
		}
	}
	return 0;
}
