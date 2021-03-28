//bracket sequence
//https://codeforces.com/problemset/problem/149/D
//1900

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
#define mul(a, b) ((((ll)a)%mod * ((ll)b)%mod)%mod)
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
const int MX = 7e2 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

ll dp[MX][MX][5][5], n;
char str[MX];
int match[MX], st[MX];

void gmatch(){
  int ind = 0;
  for(int i = 0; i<n; i++){
    if(str[i] == '(') st[ind++] = i;
    else{
      match[i] = st[--ind];
      match[match[i]] = i;
    }
  }
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  oom("%s", str);
  n = strlen(str);
  for(int i = 0; i<n; i++){
    dp[i][i + 2][0][1] = dp[i][i + 2][0][2] = dp[i][i + 2][1][0] = dp[i][i + 2][2][0] = 1ll;
  }
  gmatch();
  for(int len = 1; len<=n; len++){
    for(int i = 0; i + len + 1 <= n; i++){
      int j = i + len + 1;
      if(match[i] == j - 1){
        assert(match[j - 1] == i);
        for(int a = 0; a<3; a++){
          for(int b = 0; b<3; b++){
            if(a != 1) dp[i][j][0][1] = add(dp[i][j][0][1], dp[i + 1][j - 1][a][b]);
            if(a != 2) dp[i][j][0][2] = add(dp[i][j][0][2], dp[i + 1][j - 1][a][b]);
            if(b != 1) dp[i][j][1][0] = add(dp[i][j][1][0], dp[i + 1][j - 1][a][b]);
            if(b != 2) dp[i][j][2][0] = add(dp[i][j][2][0], dp[i + 1][j - 1][a][b]);
          }
        }
      }else{
        int k = match[i] + 1;
        for(int a = 0; a <3; a++){
          for(int b = 0; b <3; b++){
            for(int p = 0; p <3; p++){
              for(int q = 0; q <3; q++){
                if(((p == 1) || (p == 2)) && (p == q)) cont;
                dp[i][j][a][b] = add(dp[i][j][a][b], mul(dp[i][k][a][p], dp[k][j][q][b]));
              }   
            }
          }
        }
      }
    }
  }
  ll ans = 0ll;
  for(int i = 0; i<3; i++){
    for(int j = 0; j<3; j++){
      ans += dp[0][n][i][j];
    }
  }
  moo("%lld\n", (ans)%mod);
	return 0;
}


