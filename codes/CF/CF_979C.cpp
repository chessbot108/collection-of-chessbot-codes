#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>

#define int_max 0x3f3f3f3f
#define cont continue
#define pow_2(n) (1 << (n))
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))

const ll mod = 1e9 + 7;
const int max_v = 3e5 +10;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}
//should just be a tree dfs
//count the number of nodes in A's subtree
//multiply by the number in B's subtree by PIE
//then n * (n - 1) - the previous value should be it
//its jsut making sure i get the subtrees right is a pain.
//so i will root the tree and A and just subtract the subtree that B is in
//that should work

int vis[max_v], sub[max_v], par[max_v];
int n, A, B; //cant reach B after reaching A
vector<int> adj[max_v];


int dfs(int u, int p){
  par[u] = p;
  for(int v : adj[u]){
    if(v != p){
      sub[u] += dfs(v, u);
    }
  }
  return ++sub[u];
}

void taint(int u){
  if(u == A) return ;
  vis[u] = 1;
  taint(par[u]);
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> A >> B;
  for(int i = 1; i<n; i++){
    int a, b; cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  dfs(A, 0);
  taint(B);
  for(int v : adj[A]){
    if(vis[v]) sub[A] -= sub[v];
  }
  ll tot = (ll)n * (ll)(n - 1);
  ll invalid = (ll)sub[A] * (ll)sub[B];
  cout << tot - invalid << '\n';
	return 0;
}


