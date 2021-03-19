#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
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
#define init(arr, val) memset(arr, val, sizeof(arr))
//geniousity limit exceeded
#define moo printf
#define oom scanf
const ll mod = 1e9 + 7;
const int MX = 1e5 +10, int_max = 0x3f3f3f3f;
using namespace std;
 
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

struct node{
  int u; ll w;
  node(){}
  node(int a, ll b){ u = a, w = b;}
  bool operator < (const node& b) const{
    return w > b.w;
  }
};

ll dist[MX];
bool vis[MX];
vector<node> adj[MX];
int n, m;
priority_queue<node> pq;

void dijkstra(int src){
  init(vis, 0);
  init(dist, 60);
  dist[src] = 0ll;
  pq.push(node(src, 0ll));
  while(pq.size()){
    int u = pq.top().u; pq.pop();
    if(vis[u]) cont;
    vis[u] = 1;
    for(const auto& e : adj[u]){
      ll t = dist[u] + e.w;
      if(dist[e.u] > t){
        dist[e.u] = t;
        pq.push(node(e.u, t));
      }
    }
  }
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 0; i<m; i++){
    int a, b; ll c; cin >> a >> b >> c;
    adj[a].pb(node(b, c));
    //adj[b].pb(node(a, c));
  }
  dijkstra(1);
  for(int i = 1; i<=n; i++) moo("%lld ", dist[i]); puts("");
  return 0;
}
