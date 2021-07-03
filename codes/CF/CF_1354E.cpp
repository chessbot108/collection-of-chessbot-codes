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
const int MX = 5e3 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[MX][MX]; //0, 1 if n2 is 2, -1 if n2 is 1,3
int n, m, n1, n2, n3, cnt, cnt2;
vector<int> adj[MX];

int vis[MX];
vector<pair<int, pii>> comp; //id, n1+n3, n2

int dfs(int u, int c){
	//cout << u <<  " " << c << " " << vis[u] << endl;
	if(vis[u]) return (vis[u] == c);
	//cout << u << " " << c << " " << op << endl;
	vis[u] = c;
	int ans = 1; cnt++, cnt2 += (c == 2);
	for(int v : adj[u]){
		ans &= dfs(v, 3 - c);
	}
	return ans;
}

void dfs2(int u){
	if(!vis[u]) return ;
	vis[u] = 0;
	for(int v : adj[u]) dfs2(v);
}

int solve(){
	int bip = 1;
	for(int i = 1; i<=n; i++){
		if(!vis[i]){
			cnt = cnt2 = 0;
			bip &= dfs(i, 1);
			//if(cnt2 > cnt - cnt2) dfs(i, 2, 1);
			comp.pb(mp(i, mp(cnt, cnt2)));
		}
	}
	if(!bip) return 0;
	//cout << "bipartite" << endl;	
	for(int i = 0; i<siz(comp); i++){
		int a = comp[i].second.second, b = comp[i].second.first - a;
		//cout << comp[i].first << " " << a << " " << b << endl;
		for(int j = n2; ~j; j--){
			//if(i == 1) cout << j << " " << j - 1 << " " << dp[i][j - 1] << endl;
			if((j - a >= 0 && i && dp[i - 1][j - a]) || (i == 0 && j == a)) dp[i][j] = 1;
			//cout << dp[i][j];
			if((j - b >= 0 && i && dp[i - 1][j - b]) || (i == 0 && j == b)) dp[i][j] = 2;
			//cout << dp[i][j] << " ";
		} 
		//cout << endl;
	}
	//cout << dp[size(comp)-1][n2] << endl;
	return dp[siz(comp)-1][n2];
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
	cin >> n1 >> n2 >> n3;
	for(int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	if(!solve()) cout << "NO\n";
	else{
		cout << "YES\n";
		for(int i = siz(comp)-1; ~i; i--){
			dfs2(comp[i].first); cnt = cnt2 = 0;
			dfs(comp[i].first, dp[i][n2]); 	
			//cout << vis[comp[i].first] << " " << i << " " << comp[i].first << " " << dp[i][n2] << " " << n2 << " " << cnt << " " << cnt2 << endl;
			n2 -= cnt2;
		}	
		for(int i = 1; i<=n; i++){
			if(vis[i] == 1){
				if(n3){ cout << 3; n3--;}
				else cout << 1;
			}else{
				cout << 2;
			}
		}
		cout << "\n";
	}
  return 0;
}


