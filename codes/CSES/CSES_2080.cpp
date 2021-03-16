#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
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
//#define init(arr, val) memset(arr, val, sizeof(arr))
#define init(arr, val, sz) memset(arr, val, sizeof(arr[0]) * (sz))
//geniousity limit exceeded
#define moo printf
#define oom scanf
const ll mod = 1e9 + 7;
const int MX = 2e5 + 10, int_max = 0x3f3f3f3f;
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

//standard CD problem. gonne template the cd part and add the rest as needed

int vis[MX], sub[MX], cnt[MX], n, k, dep;
vector<int> adj[MX];
ll ans;

int dfs(int u, int p){
  sub[u] = 0;
  for(int v : adj[u]){
    if(v != p && !vis[v]) sub[u] += dfs(v, u);
  }
  return ++sub[u];
}

int gcen(int u, int p, int sz){
  for(int v : adj[u]){
    if(v != p && !vis[v] && sub[v] >= sz/2) 
      return gcen(v, u, sz);
  }
  return u;
}

void gcnt(int u, int p, int op, int d){
  //moo("\tcurrent: %d, par: %d, dep: %d, op: %d\n", u, p, d, op);
  if(d > k) return ;
  if(op) cnt[d]++;
  else ans += (ll)cnt[k - d];
  dep = max(dep, d);
  for(int v : adj[u]){
    if(v != p && !vis[v])
      gcnt(v, u, op, d + 1);
  }
}

void decomp(int u){
  u = gcen(u, 0, dfs(u, 0));
  //moo("centriod: %d, cur ans %d\n", u, ans);
  vis[u] = cnt[0] = 1;
  dep = 0;
  for(int v : adj[u]){
    if(!vis[v]){
      gcnt(v, u, 0, 1);
      gcnt(v, u, 1, 1);
    }
  }
  init(cnt, 0, dep + 1);
  for(int v : adj[u]){
    if(!vis[v])
      decomp(v);
  }
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> k;
  for(int i = 1; i<n; i++){
    int a, b; cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  decomp(1);
  moo("%lld\n", ans);
	return 0;
}


