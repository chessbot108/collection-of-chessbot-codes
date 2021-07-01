
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

vector<pair<pii, pii>> edges; //cost, index, u, v
int ans[(int)(1e6+10)], super[MX][40], d[MX][40], par[MX], sz[MX], dep[MX], id[MX];
vector<pair<pii,int>> adj[MX]; //tree
multiset<int> open[MX], closed[MX];
int n, m;
int find(int x){ if(x != par[x]) par[x] = find(par[x]); return par[x]; }
void Union(int a, int b){ 
	a = find(a), b = find(b);
	if(a == b) return ; 
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	par[b] = a;
}
void mkdsu(){ for(int i = 0; i<=n; i++) par[i] = i, sz[i] = 1; }
bool cmp(const pair<pii, pii>& a, const pair<pii, pii>& b){
	return a.first.first < b.first.first;
}
void kruskals(){
	mkdsu();
	for(const auto& e : edges){
		int u = e.second.first, v = e.second.second, c = e.first.first, i = e.first.second;
		if(find(u) != find(v)){
			adj[u].pb(mp(mp(v, c), i));
			adj[v].pb(mp(mp(u, c), i));
			Union(u, v);
		}
	}
}

void dfs(int u, int p, int w, int i){
	super[u][0] = p;
	d[u][0] = w;
	dep[u] = dep[p]+1;
	id[u] = i;
	for(const auto& e : adj[u]){
		if(e.first.first != p) dfs(e.first.first, u, e.first.second, e.second);
	}		
}

void precomp(){
	for(int j = 1; (1 << j)<=n; j++){
		for(int i = 1; i<=n; i++){
			super[i][j] = super[super[i][j-1]][j-1];
			d[i][j] = max(d[i][j-1], d[super[i][j-1]][j-1]);
		}
	}
}

int k_up(int u, int k, int op){//1 for lca, 0 for max
	int a = 0;
	for(int i = 30; ~i; i--){
		if((1 << i)&k) k -= (1 << i), a = max(a, d[u][i]), u = super[u][i];
	}
	return tern(op, u, a);
}

int lca(int a, int b){
	if(dep[a] > dep[b]) swap(a, b);
	b = k_up(b, dep[b] - dep[a], 1);
	if(a == b) return a;
	for(int i = 30; ~i; i--){
		if(super[a][i] != super[b][i]) a = super[a][i], b = super[b][i];
	}
	orz(a != 0 && a != b && super[a][0] == super[b][0]);
	return super[a][0];
}

int Q(int a, int b, int c){
	int l = lca(a, b), de = dep[l], w = max(k_up(a, dep[a] - de, 0), k_up(b, dep[b] - de, 0));
	return w;
}

void Merge(int a, int b){
	//small to large go brrrrrr
	if(siz(open[a]) < siz(open[b])){
		swap(open[a], open[b]);
	}
	for(int x : open[b]) open[a].ins(x);
	open[b].clear();
}

void dfs2(int u, int p){
	for(const auto& e : adj[u]){
		if(e.first.first == p) cont;
		dfs2(e.first.first, u);
		Merge(u, e.first.first);
	}
	
	for(int x : closed[u]){ open[u].erase(open[u].find(x)); open[u].erase(open[u].find(x)); }
	if(u != 1) ans[id[u]] = tern(siz(open[u]), *open[u].begin(), 1e9);
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i<=m; i++){
		int a, b, c; cin >> a >> b >> c;
		edges.pb(mp(mp(c, i), mp(a, b)));
	}
	sort(edges.begin(), edges.end());
	kruskals();
	dfs(1, 0, 0, 0);
	precomp();
	for(const auto& e : edges){
		int i = e.first.second, w = e.first.first, u = e.second.second, v = e.second.first;
		if(dep[u] < dep[v]) swap(u, v);
		if(v != super[u][0]){ //edge not in mst
			orz(id[u] != i);	
			ans[i] = Q(u, v, w);
			open[u].ins(w);
			open[v].ins(w);
			closed[lca(u, v)].ins(w);
		}
	}
	dfs2(1, 0);
	for(int i = 1; i<=m; i++){
		orz(ans[i] >= 0);
		moo("%d\n", ans[i]);
	}
  return 0;
}


