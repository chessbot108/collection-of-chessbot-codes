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

#define int ll
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
//my intuintion might be wrong, but i think this is longest path in a DAG
//proof by magic :pray:

map<ll, ll> freq, hs;
ll arr[MX], srt[MX];
vector<ll> bit[MX];

int n, m, p;


signed main(){
  cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m >> p;
	for(int i = 0; i<n; i++){
		string a; cin >> a;
		ll v = 0;
		for(int j = 0; j<m; j++){
			v += (1ll << j) * (a[j]-'0');
		}
		for(int j = 0; j<m; j++){
			if(a[j] -'0') bit[j].pb(v);
		}
		freq[v]++;
		srt[i] = v;
	}
	sort(srt, srt + n);
	int q = unique(srt, srt + n) - srt;
	for(int i = 0; i<q; i++) hs[srt[i]] = i; //asklfalskj;f so scuffed
	for(int i = 0; i<m; i++){
		sort(adj[i].begin(), adj[i].end());
		int k = unique(adj[i].begin(), adj[i].end()) - adj[i].begin();
		adj[i].resize(k);
	}
	for(int i = 0; i<q; i++){
		int c = srt[i], b = ;
	}

  return 0;
}


