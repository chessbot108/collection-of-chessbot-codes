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
const int MX = 3e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int par[MX], n, m; 
ll sz[MX], x, arr[MX];
vector<pii> adj[MX];
vector<pii> edges;
moorz<pii> ms;
int find(int y){ if(y != par[y]) par[y] = find(par[y]); return par[y]; }
void Union(int a, int b){ a = find(a), b = find(b); par[b] = a; }

void solve(){
  ll tot = 0;
  for(int i = 1; i<=n; i++){
    tot += arr[i];
  }
  if(tot < x * (ll)(n - 1)){
    moo("NO\n");
    return ;
  }
  moo("YES\n");
  for(int i = 0; i<=n; i++) par[i] = i;
  for(int i = 1; i<=n; i++){ //the case where arr[i] >= x
    sort(adj[i].begin(), adj[i].end());
    for(const pii& cur : adj[i]){
      int v = find(cur.first), u = find(i);
      if(u == v) cont;
      if(arr[u] + arr[v] >= x){
        Union(u, v);
        moo("%d\n", cur.second);
        arr[find(u)] = arr[u] + arr[v] - x;
      }
    }
  } 
  for(int i = 1; i<=m; i++){
    int u = edges[i].first, v = edges[i].second;
    if(find(u) != find(v)){
      ms.ins(mp(arr[find(u)] + arr[find(v)], i));
    }
  }
  
  while(!ms.empty()){
    auto it = (--ms.end());
    pii cur = *it;
    ms.erase(it);
    int u =find(edges[cur.second].first), v = find(edges[cur.second].second);
    if(u != v){
      orz(arr[u] + arr[v] >= x);
      moo("%d\n", cur.second);
      Union(u, v);
      arr[find(u)] = arr[u] + arr[v] - x;
    }
  }
  
}

bool cmp(const pii& a, const pii& b){
  return arr[a.first] > arr[b.first];
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m >> x;
  for(int i = 1; i<=n; i++) cin >> arr[i];
  for(int i = 1; i<=m; i++){
    int a, b; cin >> a >> b;
    adj[a].pb(mp(b, i));
    adj[b].pb(mp(a, i));
    edges[i] = mp(a, b);
  }
  solve();

  return 0;
}


