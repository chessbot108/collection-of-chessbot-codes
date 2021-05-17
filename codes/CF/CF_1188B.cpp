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
#include <map>

#define ll long long
#define lb long double
#define pii pair<int, int>
#define pb push_back
//#define mp make_pair
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
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, mod, k, ans = 0;
map<ll, ll> mp;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> mod >> k;
  for(int i = 0; i<n; i++){
    ll x, p4, v; cin >> x;
    p4 = mul(mul(x, x), mul(x, x));
    v = p4 - mul(k, x);
    (v += mod) %= mod;
    ans += mp[v];
    mp[v]++;
  }
  moo("%lld\n", ans);
  return 0;
}


