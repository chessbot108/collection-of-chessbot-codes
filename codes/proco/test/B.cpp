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


int arr[40][40], n, sc[5], t;
char str[MX];

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i<n*n*2 - (2*n); i++){
    int x, y, c, d;
    cin >> x >> y >> c >> d;
    x*=2, y*=2, c*=2, d*=2;
    str[i] = 'A' + t;
    if(x == c){
      int m = (y + d)/2;
      arr[x][m] = 1;
      arr[x+1][m]++;
      arr[x-1][m]++;
      if(arr[x+1][m] == 4 || arr[x-1][m] == 4){
        sc[t] +=(arr[x-1][m] == 4) + (arr[x+1][m] == 4);
      }else{
        t ^= 1;
      }
    }else{
      int m = (c + x)/2;
      arr[m][y] = 1;
      arr[m][y-1]++;
      arr[m][y+1]++;
      if(arr[m][y-1] == 4 || arr[m][y+1] == 4){
        sc[t] +=(arr[m][y+1] == 4) + (arr[m][y-1] == 4);
      }else{
        t ^= 1;
      }    
    }
  }
  moo("%s\n", str);
  moo("%d %d\n", sc[0], sc[1]);
  return 0;
}


