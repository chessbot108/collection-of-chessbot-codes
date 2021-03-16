#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>

#define cont continue
#define pow2(n) (1 << (n))
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))
//geniousity limit exceeded
#define moo printf
#define oom scanf
const ll mod = 1e9 + 7;
const int MX = 1e5 +10, int_max = 0x3f3f3f3f;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int dp[600][10000];
int n, m, k;
vector<pair<int, pii>> arr;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin >> n >> m >> k;
  for(int i = 0; i<k; i++){
    int a, b, c; cin >> a >> b >> c;
    arr.pb(mp(a, mp(b, c)));
  }
  init(dp, 60);
  dp[0][0] = 0;
  sort(arr.begin(), arr.end());
  //moo("input done\n");
  for(int i = 0; i<k; i++){
    for(int j = 21*4; ~j; j--){
      for(int h = 79*4; ~h; h--){
        if(j - arr[i].first < 0 || h - arr[i].second.first < 0) break;
        dp[j][h] = min(dp[j][h], dp[j - arr[i].first][h - arr[i].second.first] + arr[i].second.second);
      }
    }   
  }
  //moo("dp done\n");
  int ans = int_max;
  for(int i = 21*4; i >= n; i--){
    for(int j = 79*4; j >= m; j--){
      ans = min(ans, dp[i][j]);
    }
  }
  moo("%d\n", ans);
	return 0;
}


