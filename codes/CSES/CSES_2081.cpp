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
#define init(arr, val, sz) memset(arr, val, sizeof(arr[0]) * (sz))
//geniousity limit exceeded
#define moo printf
#define oom scanf
const ll mod = 1e9 + 7;
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

//see if i can impl CD from memory
int n, a, b, BIT[MX], dep, sub[MX], vis[MX];
ll ans; vector<int> adj[MX];

int S(int k){ return (!k) ? 0 : (BIT[k] + S(k - lsb(k))); } 
void U(int k, int val){ for(k++; k<=n; k+=lsb(k)){ BIT[k] += val;}} //note k++ at the start
int S(int L, int R){ return S(R + 1) - S(L); }

int gsub(int u, int p){
  sub[u] = 0;
  for(int v : adj[u]){
    if(v != p && !vis[v])
      sub[u] += gsub(v, u);
  }
  return ++sub[u];
}

int gcen(int u, int p, int sz){
  for(int v : adj[u]){
    if(v != p && !vis[v] && sub[v] >= sz/2){
      return gcen(v, u, sz);
    }
  }
  return u;
}

void gcnt(int u, int p, int op, int d){
  if(d > b) return ;
  if(op) U(d, 1);
  else ans += (ll)(S(max(0, a - d), b - d)); //how is usaco.guide so fivehead
  dep = max(dep, d);
  for(int v : adj[u]){
    if(!vis[v] && v != p)
      gcnt(v, u, op, d + 1);
  }
}

void decomp(int u){
  u = gcen(u, 0, gsub(u, 0));
  //moo("centroid: %d\n", u);
  vis[u] = dep = 1;
  U(0, 1);
  for(int v : adj[u]){
    if(!vis[v]){
      gcnt(v, u, 0, 1);
      gcnt(v, u, 1, 1);
    }
  }
  for(int i = 0; i<=dep; i++) U(i, -S(i, i)); //usaco guide too smart
  for(int v : adj[u]){
    if(!vis[v]){
      decomp(v);
    }
  }
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> a >> b;
  for(int i = 1; i<n; i++){
    int a, b; cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  decomp(1);
  moo("%lld\n", ans);
	return 0;
}


