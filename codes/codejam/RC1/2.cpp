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


int fro(int a, int p){
  int t = 1;
  while(t * p < a) t *= p;
  return t;
}

bool good(int a, int p){
  int f = fro(a, p);
  int st = a/f;
  while(a>p){

    a -= st * f;
    f = fro(a, p);
    moo("%ld %ld %ld %ld\n", a, st, f, p);
    if(a/f != st + 1 || ((a/f)/(p/10) == 0)) return 0;
    st++;

    if(st == p -1) p *= 10; //???? does it work????
  }
  return 1;
}

bool good(int a){
  mool;
  for(int i = 10; i<=a; i *= 10) if(good(a, i)) return 1;
  return 0;
}


int solve(){
  int n; cin >> n;
  while(n <= 123456){
    n++;
    if(good(n)) return n;
  }
  //hahahaah
}

signed main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  for(int i = 1; i<=T; i++){
    moo("Case #%ld: %ld\n", i, solve());
  }
  return 0;
}


