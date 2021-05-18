//gyrating cat enthusiast
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
#define siz(vec) ((int)(vec.size()))

#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
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
set<int> op;
int arr[MX], n;


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--){
    cin >> n;
    op.clear();
    for(int i = 0; i<n; i++){
      cin >> arr[i];
      if(arr[i] == 0) op.ins(i);
    }
    ll ans = 0;
    for(int i = 0; i<n; i++){
      if(arr[i] == 1){
        auto it = op.lower_bound(i);
        int r = int_max, l = -int_max;
        if(it != op.end()) r = *it;
        if(it != op.begin()) l = *(--it);
        if(i - l > r - i){
          op.erase(r);
          ans += (r - i);
        }else{
          op.erase(l);
          ans += (i - l);
        }
      }
    }
    moo("%lld\n", ans);
  }
  return 0;
}


