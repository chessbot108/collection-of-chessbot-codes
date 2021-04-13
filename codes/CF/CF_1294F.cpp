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
#include <set>

#define cont continue
#define pow2(n) (1 << (n))
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ins insert

#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define tern(a, b, c) ((a) ? (b) : (c))

#define pbenq priority_queue
#define moo printf
#define oom scanf
#define mool puts("") 
#define loom getline
#define orz assert

const ll mod = 1e9 + 7;
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
  freopen((file_name+".in").c_str(), "r", stdin);
  freopen((file_name+".out").c_str(), "w+", stdout);
}

vector<int> adj[MX];
int vis[MX], par[MX], dep[MX];
int n;
void dfs(int u, int p, int d){

  dep[u] = d;
  par[u] = p; //hopefully works
  for(int v : adj[u]){
    if(v != p) 
      dfs(v, u, d + 1);
  } 
}


int far(int x){
  dfs(x, 0, 0);
  int wo = 1;
  for(int i = 1; i<=n; i++){
    if(dep[wo] < dep[i]){
      wo = i; 
    }
  }
  return wo;
}

int bfs(int l, int r){
  queue<int> q;
  init(dep, 0);
  for(int i = 1; i<=n; i++){
    if(vis[i]){
      q.push(i);
      dep[i] = 1;
    }
  }
  int d = 0, ans;
  while(!q.empty()){
    int u = q.front(); q.pop();
    if((u != l && u != r) && dep[u] > d){
      d = dep[u];
      ans = u;
    }
    for(int v : adj[u]){
      if(dep[v]) cont;
      dep[v] = dep[u] + 1;
      q.push(v);
    }
  }
  return ans;
}

void up(int u){
  if(vis[u] || !u) return ;
  vis[u] = 1;
  up(par[u]);
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i<n; i++){
    int a, b; cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  int r = far(1);
  int l = far(r);
  vis[r] = 1; up(l);
  int m = bfs(l, r);
  init(vis, 0);
  up(r); up(l); up(m);
  int tot = 0;
  for(int i = 1; i<=n; i++){
    if(vis[i]) tot++;
  }
  moo("%d\n%d %d %d\n", tot - 1, l, r, m);
  return 0;
}


