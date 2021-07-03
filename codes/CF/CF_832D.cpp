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

int super[MX][40], dep[MX];
int n, q;
void precomp(){
	for(int j = 1; (1 << j)<=n; j++){
		for(int i = 1; i<=n; i++){
			super[i][j] = super[super[i][j-1]][j-1];
		}
	}
}

int rec(int u){
	if(u == 0) return 0;
	if(dep[u]) return dep[u];
	return dep[u] = rec(super[u][0]) + 1;
}

int k_up(int u, int k){
	for(int i = 20; ~i; i--){
		if(k&(1 << i)) k -= (1 << i), u = super[u][i];
	}
	return u;
}

int lca(int a, int b){
	if(dep[a] > dep[b]) swap(a, b);
	b = k_up(b, dep[b] - dep[a]);
	if(a == b) return a;
	for(int i = 20; ~i; i--){
		if(super[a][i] != super[b][i]) a = super[a][i], b = super[b][i];
	}
	orz(a != 0 && a != b && super[a][0] == super[b][0]);
	return super[a][0];
}

int rlca(int a, int b, int c){
	int u = lca(a, b), v = lca(b, c), w = lca(a, c);
	if(u == v) return w;
	else if(u == w) return v;
	else{
		orz(w == v);
		return u;
	}
}

int dist(int a, int b){
	return (dep[a] + dep[b]) - (dep[lca(a, b)]*2);
}

int Q(int a, int b, int c){
	int l = rlca(a, b, c);
	//moo("%d %d %d, %d, %d %d\n", a, b, c, l, dist(a, l), dist(b, l));
	return max(dist(a, l), dist(b, l));
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> q;
	for(int i = 2; i<=n; i++) cin >> super[i][0];
	precomp();
	for(int i = 1; i<=n; i++) rec(i); 
	while(q--){
		int a, b, c; cin >> a >> b >> c;
		int ans = max({Q(a, b, c), Q(b, c, a), Q(c, a, b)});
		moo("%d\n", ans+1);
	}
  return 0;
}


