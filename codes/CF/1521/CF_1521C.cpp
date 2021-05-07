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
#define fll fflush(stdout)

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

//find the position of 1 in th perm with n/2 ops, then find each one

int arr[MX], n;

int q2(int i){
  moo("? %d %d %d %d\n", 2, i, i + 1, 1);
  fll;
  int d; cin >> d;
  if(d == 1){
    return i;
  } 
  if(d == 2){
    moo("? %d %d %d %d\n", 2, i + 1, i, 1);
    fll;
    cin >> d;
    if(d == 1) return i + 1;
  }
  return 0;
}


int pos1(){
  //finding pos of 1 :O
  for(int i = 1; i<=n-1; i+=2){
    int x = q2(i);
    if(x > 0) return x;
  }
  int t = q2(n-1);
  if(t > 0) return t;
  //ahhhhhhhhhhhhhhhhhhhhhh. 
  orz(0); //it should work tho :<
}



int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--){
    cin >> n;
    bckt(arr, 0, n+2);
    int m = pos1();
    for(int i = 1; i<=n; i++){
      if(i == m) cont;
      moo("? %d %d %d %d\n", 1, m, i, n - 1);
      fll;
      cin >> arr[i];
    }
    arr[m] = 1;
    moo("!");
    for(int i = 1; i<=n; i++) moo(" %d", arr[i]); mool;
    fll;
  }
  return 0;
}


