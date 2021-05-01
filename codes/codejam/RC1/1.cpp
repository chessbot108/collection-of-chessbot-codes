

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

int arr[200];


lb solve(){
  int n, k; cin >> n >> k;
  init(arr, 0);
  for(int i = 0; i<n; i++) cin >> arr[i];
  sort(arr, arr + n);
  //n = unique(arr, arr + n) - arr;
  vector<int> two, one;
  for(int i = 1; i<n; i++){
    int t = (arr[i] - arr[i - 1]);
    //moo("%ld %ld %ld\n", arr[i], arr[i - 1], t);
    two.pb(max(t - 1, 0l));
    one.pb(t/2);
  }

  one.pb(arr[0] - 1); one.pb(k - arr[n - 1]);
  sort(one.begin(), one.end());
  sort(two.begin(), two.end());
  //for(int x : one) moo("%ld ", x); mool;
  //for(int x : two) moo("%ld ", x); mool;
  int temp = tern(two.size(), two[two.size()-1], 0); //also ac with a trivial fix. imagine spending an hour and a half and failing a bronze problem
  int t = max(temp, one[one.size() - 1] + one[one.size() - 2]);
  
  return (lb)(t)/(lb)(k);
} 

signed main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  for(int i = 1; i<=T; i++){
    moo("Case #%ld: %.8LF\n", i, solve());
  }
  return 0;
}




