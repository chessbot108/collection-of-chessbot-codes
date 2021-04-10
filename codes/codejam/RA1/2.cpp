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
const int MX = 5e4 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int vis[MX], low[MX];
int tot[MX], arr[MX];

void seive(){
  for(int i = 2; i<=5e4; i++){
    if(low[i]) cont;
    for(int j = i; j<=5e4; j += i) if(!low[j]) low[j] = i;
  }
}

int solve(){
  int m, n, sum = 0; cin >> m;
  init(tot, 0);
  init(vis, 0);
  for(int i = 0; i<m; i++){
    int p, q; cin >> p >> q;
    tot[p] = q;
    sum += p * q;
  }
  int ans = 5e4; //looping over the max sum
  while(ans-- > 1){
    int cnt = 0, wo = 1;
    for(int i = ans; i != 1 && wo; i /= low[i]){
      //moo("%d\n", i);
      vis[low[i]]++;
      cnt += low[i];
      if(vis[low[i]] > tot[low[i]]) wo = 0;
    }
    if(wo && ans + cnt == sum) return ans;
    for(int i = ans; i != 1; i /= low[i]) vis[low[i]] = 0;
  }
  return 0; //no sol
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  seive();
  for(int i = 1; i<=T; i++){
    moo("Case #%d: %d\n", i, solve());
  }
	return 0;
}


