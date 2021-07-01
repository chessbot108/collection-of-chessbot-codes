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

int par[MX];
ll val[MX];
vector<pair<ll, pii>> edges;

int find(int x){
	if(x != par[x]) par[x] = find(par[x]); return par[x]; 
}
void Union(int a, int b){
	par[find(a)] = find(b);
}

bool cmp(const pair<ll, pii>& a, const pair<ll, pii>& b){
	return a.first < b.first;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i<=n; i++){
		cin >> val[i]; par[i] = i;
	}
	int ind = min_element(val+1, val+n+1) - val;
	for(int i = 1; i<=n; i++){
		if(i != ind) edges.pb(mp(val[ind] + val[i], mp(i, ind)));
	}
	while(m--){
		int a, b; ll c; cin >> a >> b >> c;
		edges.pb(mp(c, mp(a, b)));
	}
	sort(edges.begin(), edges.end(), cmp);
	ll tot = 0;
	for(auto it : edges){
		int u = it.second.first, v = it.second.second;
		if(find(u) != find(v)){
			Union(u, v);
			tot += it.first;
		}
	}
	moo("%lld\n", tot);
  return 0;
}


