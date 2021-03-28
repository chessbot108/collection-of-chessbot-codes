//eat the trees
//https://vjudge.net/problem/HDU-1693
//https://blog.csdn.net/bossup/article/details/9405119?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-5&spm=1001.2101.3001.4242
//csdn blogs op
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

ll dp[12][12][pow2(13) +10];
int arr[12][12], n, m;

ll solve(){
  init(dp, 0);
  init(arr, 0);
  cin >> n >> m;
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m; j++){
      cin >> arr[i][j];
    }
  } 
  dp[0][m][0] = 1ll;
  for(int i = 1; i<=n; i++){
    for(int sta = 0; sta < pow2(m); sta++)
      dp[i][0][sta*2] = dp[i-1][m][sta];
    for(int j = 1; j<=m; j++){
      int u, r, d, l;
      u = r = pow2(j);
      d = l = pow2(j - 1);
      for(int sta = 0; sta < pow2(m + 1); sta++){
        if(arr[i][j]){ //tree
          if((sta&r) && (sta&d)){ //two output
            dp[i][j][sta] = dp[i][j - 1][sta - (u + l)]; //state from which there is no out
          }else if(!(sta&r) && !(sta&d)){ //zero output
            dp[i][j][sta] = dp[i][j - 1][sta + u + l]; //state from two input
          }else{ //state from 1 input
            dp[i][j][sta] = dp[i][j - 1][sta] + dp[i][j - 1][sta^u^l]; //state from 1 input
            //using xor since it does it really fast :O
          } 
        }else{ //no tree
          if(!(sta&r) && !(sta&d)){ //zero coming out :/
            dp[i][j][sta] = dp[i][j - 1][sta];
          }else{
            dp[i][j][sta] = 0ll; //something coming out of no tree?
          }
        }
      }
    }
  }
  return dp[n][m][0];
} 


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  for(int i = 1; i<=T; i++){
    moo("Case %d: There are %lld ways to eat the trees.\n", i, solve());
  }
	return 0;
}


