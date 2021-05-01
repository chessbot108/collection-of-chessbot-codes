//closest pick
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
#define int long //ARE YOU READY FOR WAR CRIMES WITH ME
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
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int arr[200], n, k;

int vis[40], dist[40];


int eval(int a, int b){
  init(vis, 0);
  for(int i = a; (i>0) && (dist[i] > a - i); i--)
    vis[i] = 1;

  for(int i = b; (i>0) && (dist[i] > b - i); i--)
    vis[i] = 1;
  for(int i = a; (i<=k) && (dist[i] > i - a); i++)
    vis[i] = 1;


  for(int i = b; (i<=k) && (dist[i] > i - b); i++)
    vis[i] = 1;

  int tot = 0;
  for(int i = 1; i<=k; i++) tot += vis[i];
  return tot;
}

lb solve(){
  cin >> n >> k;
  for(int i = 0; i<n; i++){
    cin >> arr[i];
  }
  init(dist, 0x3f);
  for(int i = 0; i<n; i++){
    for(int j = arr[i]; j>0; j--) dist[j] = min(dist[j], arr[i] - j);
    for(int j = arr[i]; j<=k; j++) dist[j] = min(dist[j], j - arr[i]);
  }  
  //for(int i = 1; i<=30; i++) moo("%d ", dist[i]); mool;
  int ans = 0;
  for(int i = 1; i<=k; i++){
    for(int j = i + 1; j<=k; j++){
      ans = max(ans, eval(i, j));
    }
  }

  return (lb)ans/(lb)k;

} 

signed main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  for(int i = 1; i<=T; i++){
    moo("Case #%ld: %.8LF\n", i, solve());
  }
  return 0;
}



