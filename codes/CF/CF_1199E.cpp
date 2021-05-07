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

int vis[MX], n, m;
vector<pair<pii, int>> edges;
vector<int> ans;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--){
    cin >> n >> m;
    bckt(vis, 0, n*3 +5);
    edges.clear();
    ans.clear();
    for(int i = 0; i<m; i++){
      int a, b; cin >> a >> b;
      edges.pb(mp(mp(a, b), i + 1));
    }
    for(int i = 0; i<m; i++){
      int u = edges[i].first.first, v = edges[i].first.second, w = edges[i].second;
      if(!vis[u] && !vis[v]){
        vis[u] = vis[v] = 1;
        ans.pb(w);
      }
    }
    if(ans.size() >= n){
      moo("Matching\n");
      for(int i = 0; i<n; i++) moo("%d ", ans[i]); mool;
    }else{
      moo("IndSet\n");
      int cnt = 0;
      for(int i = 0; i<n*3 && cnt<n; i++){
        if(!vis[i+1]){
          cnt++;
          moo("%d ", i + 1);
        }
      }
      mool;
    }
  }
  return 0;
}


