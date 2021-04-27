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

#define cont continue
#define pow2(n) (1 << (n))
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ins insert

#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define tern(a, b, c) ((a) ? (b) : (c))

#define pbenq priority_queue
#define moo printf
#define oom scanf
#define mool puts("") 
#define loom getline
#define orz assert

const ll mod = 1e9 + 7;
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
  freopen((file_name+".in").c_str(), "r", stdin);
  freopen((file_name+".out").c_str(), "w+", stdout);
}

ll a[MX], b[MX];
ll n, k;

bool check(ll x){
  //can i bake x cookies
  ll tot = 0;
  for(int i = 0; i<n && tot <= k; i++){
    if(b[i] < a[i] * x){
      tot += a[i] *x - b[i];
    }
  }
  return (tot <= k);
}


ll bsearch(ll l, ll r){
  //moo("%lld %lld\n", l, r);
  if(r - l  < 10ll){
    for(ll i = r; i>=l; i--){
      if(check(i)) return i;
    }
  }
  ll mid = (l + r)/2ll;
  if(check(mid)){
    return bsearch(mid, r);
  }else{
    return bsearch(l, mid);
  }


}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> k;
  for(int i = 0; i<n; i++){
    cin >> a[i];
  }
  for(int i = 0; i<n; i++){
    cin >> b[i];
  }
  ll temp = 2e9;
  moo("%lld\n", bsearch(0ll, temp));
  return 0;
}


