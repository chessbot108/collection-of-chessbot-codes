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
const int MX = 100 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());


int arr[MX][MX];


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--){
    int n; cin >> n;
    init(arr, 0);
    if(n == 1){
      moo("1\n"); cont;
    }else if (n == 2){
      moo("-1\n"); cont;
    }else if(n == 3){
      moo("2 9 7\n4 6 3\n1 8 5\n");
      cont;
    }else if(n == 4){
      moo("1 3 9 13\n4 8 12 16\n2 6 10 14\n5 15 7 11\n");
      cont;
    }
    for(int i = 0; i<n; i++){
      for(int j = 0; j<n; j++){
        if(j%2 == 0) arr[i][j/2] = i*n +j;
        else arr[i][(n/2 + n%2 +j/2)] = i*n +j;
      }
    }
    for(int i = 0; i<n; i++){
      for(int j = 0; j<n; j++){
        moo("%d ", arr[i][j] + 1);
        //orz(abs(arr[i][j] - arr[i][j + 1]) != 1 && abs(arr[i][j] - arr[i + 1][j]));
      } mool;
    }
  } 
  return 0;
}


