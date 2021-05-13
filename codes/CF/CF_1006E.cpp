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
int trav[MX], occ[MX], ind, rind = 0, sub[MX];
int n, q;

int dfs(int u, int p){
  trav[ind] = u;
  occ[u] = ind++;
  for(int v : adj[u]){
    if(v != p) sub[u] += dfs(v, u);
  }
  return ++sub[u];
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> q;
  for(int i = 2; i<=n; i++){
    int a, b = i; cin >> a;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  dfs(1, 0);
  //for(int i = 0; i<n; i++) moo("%d ", trav[i]); mool; 
  //for(int i = 1; i<=n; i++) moo("%d ", occ[i]); mool;
  while(q--){
    int a, b; cin >> a >> b; b--;
    //moo("%d %d %d\n", occ[a], b, trav[oc[a] + b]);
    if(b >= sub[a]) moo("-1\n");
    else moo("%d\n", trav[occ[a] + b]);
  }
  return 0;
}


