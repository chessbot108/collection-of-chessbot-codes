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
const int MX = 1e2 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int arr[MX];

int solve(){
  int m, n = 0; cin >> m;
  for(int i = 0; i<m; i++){
    int q, p; cin >> q >> p;
    while(p--){
      arr[n++] = q;
    }
  }
  //for(int i= 0; i<n; i++) moo("%d ", arr[i]); mool;
  int ans = 0;
  if(n > 10) return 0; //be nice to the server :)
  for(int i = 0; i<pow2(n); i++){
    int s = 0, p = 1;
    for(int j = 0; j<n && p <= (int)1e6; j++){
      if(i&pow2(j)) s += arr[j];
      else p *= arr[j];
    }
    if(s == p) ans = max(ans, s);
  }
  return ans;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  for(int i = 1; i<=T; i++){
    moo("Case #%d: %d\n", i, solve());
  }
	return 0;
}


