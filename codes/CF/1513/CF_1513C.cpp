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
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

ll dp[MX][20]; //operations, digit

void precomp(){
  for(int i = 0; i<=9; i++) dp[0][i] = 1ll; //base case;
  for(int i = 1; i<=2e5; i++){
    for(int j = 0; j<9; j++){
      dp[i][j] = dp[i - 1][j + 1];
      if(dp[i][j] >= mod) dp[i][j] %= mod;
    }
    dp[i][9] = add(dp[i - 1][1], dp[i - 1][0]);
    /**
     if(i <= 10){
      for(int j = 0; j<=9; j++){
        moo("%6d", dp[i - 1][j]);
      }
      mool;
    }
    **/
  }
  
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  precomp();
  int T; cin >> T;
  while(T--){
    int n, m; cin >> n >> m;
    ll tot = 0ll;
    while(n){
      tot = add(tot, dp[m][n%10]);
      n /= 10;
    }
    moo("%lld\n", tot % mod);
  }
	return 0;
}


