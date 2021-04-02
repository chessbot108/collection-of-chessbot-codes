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

int board[10][10];
char str[10];

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; oom("%d%d", &n, &m);
  for(int i = 0; i<n; i++){
    init(str, 0);
    oom("%s", str);
    assert(strlen(str) == m);
    for(int j = 0; j<m; j++){
      board[i][j] = tern(str[j] == '*', 1, 0);
    }
  }
  int x = 0, y = 0, ans = 0;
  for(int i = 0; i<n + m + 2; i++){
    ans += board[x][y];
    //moo("%d %d\n", x, y);
    if(i%2 == 0) x++;
    else y++;
  }
  moo("%d\n", ans);
	return 0;
}


