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

int deg[MX], par[MX], cnt[MX], n, m;
vector<int> adj[MX], ans;
int find(int x){ if(x != par[x]) par[x] = find(par[x]); return par[x]; }
void Union(int a, int b){
  a = find(a), b = find(b);
  par[a] = b;
}
void mkdsu(){ for(int i = 0; i<=n; i++) par[i] = i; }


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 0; i<=n; i++) deg[i] = n-1;
  for(int i = 0; i<m; i++){
    int a, b; cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
    deg[a]--, deg[b]--;
  }
  mkdsu();
  for(int i = 1; i<=n; i++){
    if(deg[i] > n/2){
      Union(0, i);
      cont;
    }
    sort(adj[i].begin(), adj[i].end());
    int p = 0;
    for(int j = 1; j<=n; j++){
      if(p != adj[i].size() && adj[i][p] == j){ 
        p++; cont;
      }
      Union(i, j);
    } 
  }
  
  for(int i = 1; i<=n; i++) cnt[find(i)]++;
  for(int i = 1; i<=n; i++){
    if(find(i) == i){
      ans.pb(cnt[i]);
    }
  }
  moo("%d\n", (int)ans.size());
  sort(ans.begin(), ans.end());
  for(int i = 0; i<ans.size(); i++){
    moo("%d ", ans[i]);
  } mool;
  
  
  return 0;
}


