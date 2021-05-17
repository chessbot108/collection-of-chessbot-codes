//code by me
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
const ll mod = 1e9 + 7, ll_max = (ll)1e18;
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());


int arr[MX], arr2[MX], ans[MX];
int n;
ll k, m;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  if(n == 1){
    moo("0\n"); return 0;
  }
  for(int i = 0; i<n; i++){
    cin >> arr[i];
    arr2[i] = arr[i];
  }
  for(int i = 1; i<n; i++){
    if(arr[i]%2 == arr[i-1]%2){
      k++;
      arr[i]++;
      //moo("\t%d\n", i);
    }
  }
  //moo("plan 2\n");
  //reverse(arr2, arr2 + n);
  for(int i = 0; i<n-1; i++){
    if(i == 0 && arr2[0]%2 == arr2[1]%2){
      arr2[0]++;
      m++;
    }
    if(arr2[i]%2 == arr2[i+1]%2){
      m++;
      arr2[i+1]++;
      //moo("\t%d\n", i);
    }
  }
  
  moo("%lld\n", min(m, k));
  return 0;
}


