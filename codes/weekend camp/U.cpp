//ping pong
//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=4174
//UVa 1428
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
#define cont continue

#define pow2(n) (1 << (n))
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ins insert
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define tern(a, b, c) ((a) ? (b) : (c))
//the following ones give off usaco vibes
#define pbenq priority_queue
#define moo printf
#define oom scanf
#define mool puts("") 
#define loom getline

const ll mod = 1e9 + 7;
const int MX = 1e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int BIT[MX*2], n, arr[MX];
int pre[MX], suf[MX];
vector<pii> vec;

int S(int k){ return tern(!k, 0, BIT[k] + S(k - lsb(k))); }
void U(int k, int val){ for(; k<=1e5; k+=lsb(k)) BIT[k] += val; }


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  //setIO("U");
  int T; cin >> T;
  while(T--){
    init(BIT, 0); init(arr, 0);
    init(pre, 0); init(suf, 0); 
    vec.clear();
    cin >> n;
    for(int i = 0; i<n; i++){
      cin >> arr[i];
      vec.pb(mp(arr[i], i));
    }
    
    for(int i = 0; i<n; i++){
      pre[i] = S(arr[i]);
      U(arr[i], 1);
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i<n; i++){
      suf[vec[i].second] = i - pre[vec[i].second];  
    }
    ll ans = 0ll;
    for(int i = 0; i<n; i++){
      ans += (ll)(pre[i]) * (ll)(n - i - 1 - suf[i]);
      ans += (ll)(suf[i]) * (ll)(i - pre[i]);
    }
    moo("%lld\n", ans);
  }
	return 0;
}


