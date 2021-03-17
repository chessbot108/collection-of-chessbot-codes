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
#include <queue>

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

vector<int> adj[MX];
queue<int> q;
int vis[MX], par[MX], inq[MX], dist[MX], n, m;
bool bfs(int src){
  q.push(src);
  dist[src] = 1;
  while(q.size()){
    int u = q.front(); q.pop();
    if(u == n) return 1;
    vis[u] = 1;
    inq[u] = 0;
    for(int v : adj[u]){
      if(!inq[v] && !vis[v]){
        inq[v] = 1;
        par[v] = u;
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  return 0;
}

void print(int u){
  if(u == 1){
    moo("1");
  }else{
    print(par[u]);
    moo(" %d\n", u);
  }
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 0; i<m; i++){
    int a, b; cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  if(!bfs(1)){
    moo("IMPOSSIBLE\n");
  }else{
    moo("%d\n", dist[n]);
    print(n);
  }
	return 0;
}


