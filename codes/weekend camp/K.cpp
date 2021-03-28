//make equal, first 3100 :OOOOOOOOO
//https://codeforces.com/contest/1188/problem/D
//editorial op
//https://pastebin.com/usq1czKq
//editorial op, me using it antiorz
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

#define pow2(n) (1ll << ((ll)n))
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

const ll mod = 1e9 + 7, INF = pow2(62);
const int MX = 2e5 +10, int_max = 0x3f3f3f3f, LOGN = 62;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

ll dp[MX+10][LOGN +10], arr[MX], a[MX];
int n, pre0[MX], pre1[MX];

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  ll T = 0ll;
  for(int i = 1; i<=n; i++){
    cin >> arr[i];
    T = max(arr[i], T);
  }
  
  for(int i = 1; i<=n; i++){
    a[i] = T - arr[i];
  }
  
  for(int i = 0; i<=MX; i++){
    for(int j =0; j<=LOGN; j++){
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0ll;
  vector<int> v;
  for(int i = 1; i<=n; i++) v.pb(i);
  for(int j = 0; j<=LOGN; j++){
    if(j){
      vector<int> newv;
      for(int x : v){
        if(!(a[x] & pow2(j - 1))) newv.pb(x);
      }

      for(int x : v){
        if((a[x] & pow2(j - 1))) newv.pb(x);
      }
      v = newv;
    }
    init(pre0, 0);
    init(pre1, 0);
    for(int i = 1; i<=n; i++){
      pre0[i] = pre0[i - 1];
      pre1[i] = pre1[i - 1];
      if(a[v[i - 1]] & pow2(j)) pre1[i]++;
      else pre0[i]++;
    }
    int tot0 = pre0[n], tot1 = pre1[n];
    assert(tot0 + tot1 == n); //thonk
    for(int i = 0; i<=n; i++){
      //moo("dp[%d][%d] == %lld\n", i, j, dp[i][j]);
      for(int bt = 0; bt <2; bt++){
        if(dp[i][j] == INF) cont;
        int inv = (n - i);
        if(bt == 0){
          int num = (tot0 - pre0[inv]) + pre1[inv];
          int carry = tot1 - pre1[inv];
          dp[carry][j + 1] = min(dp[carry][j + 1], dp[i][j] + (ll)num);
        }else{
          int num = (tot1 - pre1[inv]) + pre0[inv];
          int carry = n - pre0[inv];
          dp[carry][j + 1] = min(dp[carry][j + 1], dp[i][j] + (ll)num);
        }
      }
    }
  }
  moo("%lld\n", dp[0][LOGN]);
	return 0;
}


