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
#include <set>

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

#define moo printf
#define oom scanf
#define mool puts(""); 
#define loom getline
const ll mod = 1e9 + 7;
const int MX = 5e2 +10, int_max = 0x3f3f3f3f;
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

set<int> adj[MX], adj2[MX];
int arr[MX][MX], R[MX], C[MX], cost[MX][MX];
vector<pair<int, pii>> vec;
vector<int> q;

void process(int x, int y){
  //moo("\terasing: %d %d\n", x, y);
  adj[x].erase(y);
  adj2[y].erase(x);
  arr[x][y] = 1;
  if(adj[x].size() == 1){
    process(x, *adj[x].begin());
  }
  if(adj2[y].size() == 1){
    process(*adj2[y].begin(), y);
  }
}

void mktc(){
  for(int i = 0; i<=501; i++){
    adj[i].clear(); adj2[i].clear();
  }
  init(arr, 0);
  init(cost, 0);
  vec.clear();
  q.clear();
}

int solve(){
  mktc();
  int n; cin >> n;
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n; j++){
      cin >> arr[i][j];
      if(arr[i][j] == -1){
        adj[i].insert(j);
        adj2[j].insert(i);
      }
    }
  }
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n; j++){
      cin >> cost[i][j];
      if(cost[i][j]){
        vec.pb(mp(cost[i][j], mp(i, j)));
      }
    }
  }
  sort(vec.begin(), vec.end());
  for(int i = 0; i<n; i++){
    cin >> R[i];
  }
  for(int j = 0; j<n; j++){
    cin >> C[j];
  }
  for(int j = 0; j<n; j++){
    for(int i = 1; i<=n; i++){
      if(adj[i].size() == 1) process(i, *adj[i].begin());
      if(adj2[i].size() == 1) process(*adj2[i].begin(), i);
    }
  }
  int ans = 0;
  for(const auto& e : vec){
    if(arr[e.second.first][e.second.second] >= 0) cont;
    ans += e.first;
    process(e.second.first, e.second.second);
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


