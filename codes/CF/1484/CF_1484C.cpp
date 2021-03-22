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
const int MX = 1e5 +10, int_max = 0x3f3f3f3f;
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

vector<int> adj[MX], adj2[MX];
int cnt[MX], ans[MX];
void solve(){
  int n, m; cin >> n >> m;
  for(int i = 0; i<=n+5; i++){ cnt[i] = 0; adj2[i].clear(); }
  for(int i = 1; i<=m; i++){
    adj[i].clear(); 
    ans[i] = 0;
    int k; cin >> k;
    if(k == 1){
      int a; cin >> a;
      cnt[a]++;
      adj[i].pb(a);
    }else{
      for(int j = 0; j<k; j++){
        int a; cin >> a;
        adj[i].pb(a);
        adj2[a].pb(i);
      }
    }
  }
  //moo("input done\n");
  int mx = 0, f;
  for(int i = 1; i<=n; i++){
    if(mx < cnt[i] || (cnt[i] == 0 && mx == 0 && adj2[i].size())){
      mx = cnt[i];
      f = i;
    }
  }
  if(mx > (m + 1)/2){
    moo("NO\n");
    return ;
  }
  moo("YES\n");
  for(int i = 1; i<=m; i++){
    if(adj[i].size() == 1){
      ans[i] = adj[i][0];
    }
  }
  
  for(int i = 1; i<=n; i++){
    for(int v : adj2[i]){
      if(ans[v] || cnt[i] >= (m+1)/2) cont;
      ans[v] = i; cnt[i]++;
    }
  }

  for(int i = 1; i<=m; i++){
    moo("%d ", ans[i]);
  }
  mool
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  for(int i = 0; i<T; i++){
    solve();
  }
	return 0;
}


