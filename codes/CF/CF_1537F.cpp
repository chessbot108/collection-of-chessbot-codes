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

vector<int> adj[MX];
ll vis[MX], tar[MX], val[MX];
int n, m;

int dfs(int u, int c){
	if(vis[u]) return (vis[u] == c);
	int ans = 1;
	vis[u] = c;
	for(int v : adj[u]){
		ans &= dfs(v, 3-c);
	}
	return ans;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		cin >> n >> m;
		bckt(vis, 0, n);
		bckt(tar, 0, n);
		bckt(val, 0, n);
		for(int i = 0; i<=n; i++) adj[i].clear();
		for(int i = 1; i<=n; i++) cin >> val[i];
		for(int i = 1; i<=n; i++) cin >> tar[i];
		for(int i = 0; i<m; i++){
			int a, b; cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		ll t1 = 0, t2 = 0;
		for(int i = 1; i<=n; i++) t1 += tar[i], t2 += val[i];
		if((t1-t2)%2){
			cout << "NO\n"; cont;
		}
		int b = dfs(1, 1); t1 = t2 = 0;
		if(b){
			for(int i = 1; i<=n; i++){
				//cerr << i << " " << vis[i] << " " << (tar[i] - val[i]) << endl;
				if(vis[i] == 1) t1 += (tar[i] - val[i]);
				else t2 += (tar[i] - val[i]);
			}
			//cerr << t1 << " " << t2 << endl;
			(t1 == t2 && cout << "YES\n") || cout << "NO\n"; 
		}else{
			cout << "YES\n";
		}
	}
  return 0;
}


