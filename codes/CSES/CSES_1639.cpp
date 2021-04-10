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
const int MX = 5e3 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
 freopen((file_name+".in").c_str(), "r", stdin);
 freopen((file_name+".out").c_str(), "w+", stdout);
}
char s[MX], t[MX];
int n, m;
int dp[MX][MX];

int main(){
 cin.tie(0) -> sync_with_stdio(0);
 oom("%s%s", s + 1, t + 1);
 n = strlen(s + 1), m = strlen(t + 1);
 for(int i = 0; i<=max(n, m); i++) dp[i][0] = dp[0][i] = i;
 for(int i = 1; i<=n; i++){
   for(int j = 1; j<=m; j++){
     dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
     if(s[i] == t[j]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
   }
 }
 moo("%d\n", dp[n][m]);
 return 0;
}
