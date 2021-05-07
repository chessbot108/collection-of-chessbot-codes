//here take a cat
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <utility>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <queue>
#include <set>

#define ll long long
#define lb long double
#define moorz multiset
#define apple multimap
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ins insert
#define cont continue
#define pow2(n) (1 << (n))

#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define bckt(arr, val, sz) memset(arr, val, sizeof(arr[0]) * (sz))
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define tern(a, b, c) ((a) ? (b) : (c))
#define feq(a, b) (fabs(a - b) < eps)
#define A first 
#define B second


#define pbenq priority_queue
#define moo printf
#define oom scanf
#define mool puts("") 
#define loom getline
#define orz assert
//what if using geniousities in my macros
//will boost my chances at ac?
//might as well try it out

const lb eps = 1e-9;
const ll mod = 1e9 + 7;
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, dist = 0, D;
vector<int> adj[MX];
vector<pair<pii, pii>> ans;
int dfs(int u, int p){ //returns the end of the bamboo
  if(adj[u].size() == 1 && u != D) return u; //leaf node, base case
  //moo("%d %d\n", u, p);
  int st = tern(adj[u][0] == p, adj[u][1], adj[u][0]), en = dfs(st, u); //solve for one leaf
  for(int i = 0; i<adj[u].size(); i++){
    int v = adj[u][i];
    if(v == p || v == st) cont;
    int temp = dfs(v, u);
    //moo("%d %d %d %d\n", u, v, st, v);
    ans.pb(mp(mp(u, v), mp(en, v)));
    en = temp;
  }
  return en;
}


void gdia(int u, int p, int d){
  if(d > dist){
    dist = d, D = u;
  }
  for(int v : adj[u]) if(v != p) gdia(v, u, d + 1);
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--){
    cin >> n;
    for(int i = 0; i<=n; i++) adj[i].clear();
    ans.clear();
  
    for(int i = 1; i<n; i++){
      int a, b; cin >> a >> b;
      adj[a].pb(b);
      adj[b].pb(a);
    }
  
    dist = 0; gdia(1, 0, 0);
    dfs(D, 0);
    //moo("dia -> %d\n", D);
    moo("%d\n", (int)ans.size());
    orz(ans.size() <= n);
    for(const auto& p : ans){
      moo("%d %d %d %d\n", p.A.A, p.A.B, p.B.A, p.B.B);
    }
  }
  return 0;
}


