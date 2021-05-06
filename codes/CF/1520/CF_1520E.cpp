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
const int MX = 1e6 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

char str[MX];
int arr[MX], n;


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; oom("%d", &T);
  while(T--){
    oom("%d", &n);
    bckt(arr, 0, n+5);
    bckt(str, 0, n+5);
    oom("%s", str);
    int p = 0, met = 0, s = 0;
    ll st = 0, ans = 1e15;
    for(int i = 0; i<n; i++){
      if(str[i] == '*'){
        st += (ll)(i - p);
        arr[i] = p++;
      }
    }
    //moo("%lld\n", st);
    orz(p <= n);
    for(int i = 0; i<n-p; i++){
      ans = min(ans, st);
      while(str[s + i] == '*' && s<p){
        
        //moo("%d, %lld, %lld, %lld\n", i, st, p - met, met);
        //we've met a sheep
        met++;
        s++;
      }
      //moo("%d, %lld, %lld, %lld\n", i, st, p - met, met);
      st += met - (p - met);
    }
    
    ans = min(ans, st);
    moo("%lld\n", ans);
  }
  return 0;
}


