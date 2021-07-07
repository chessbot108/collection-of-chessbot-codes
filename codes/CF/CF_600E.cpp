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
#include <map>

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
//heavily inspired by moo's
int n;
ll arr[MX], ans[MX];
map<ll, ll> cnt[MX], freq[MX];
vector<int> adj[MX];

void merge(int a, int& b){
	if(siz(cnt[a]) > siz(cnt[b])) swap(a, b);
	for(const auto& x : cnt[a]){
		cnt[b][x.first] += x.second;
		freq[b][cnt[b][x.first]] += x.first;
	}
	cnt[a].clear();
	freq[a].clear();
}

void dfs(int& u, int p){
	int t = u;
	for(int v : adj[t]){
		if(v == p) cont;
		dfs(v, t);
		merge(v, u);
	}
	//cout << u << endl;
	//for(auto e : freq[u]) cout << e.first << " " << e.second << endl;
	ans[t] = prev(freq[u].end())->second;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
		cnt[i][arr[i]] = 1;
		freq[i][1] = arr[i];
	}
	for(int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	int t = 1;
	dfs(t, 0);
	for(int i = 1; i<=n; i++){
		moo("%lld ", ans[i]);
	}
	mool;
  return 0;
}


