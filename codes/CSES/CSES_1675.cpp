#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#define ll long long 
#define pb push_back
using namespace std;
const int max_v = 1e5 +10;
struct node{
  ll v; int u;
  node(){}
  node(int a, ll b){ u = a, v = b;}
  bool operator < (const node& b) const{
    return v > b.v;
  }

};
priority_queue<node> pq;
ll dist[max_v];
bool vis[max_v];
vector<node> adj[max_v];
int n, m;

ll prim(int src){
  ll ans = 0ll;
  memset(dist, 60, sizeof(dist));
  dist[src] = 0ll;
  pq.push(node(src, 0ll));
  while(!pq.empty()){
    int u = pq.top().u; pq.pop();
    if(vis[u]) continue;
    vis[u] = 1; ans += dist[u];
    for(node e : adj[u]){
      int v = e.u;
      if(e.v < dist[v]){
        dist[v] = e.v;
        pq.push(node(v, dist[v]));
      }
    }
  }
  for(int i = 1; i<=n; i++){
    if(!vis[i]) return -1;
  }
  return ans;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 0; i<m; i++){
    int a, b; ll c;
    cin >> a >> b >> c;
    adj[a].pb(node(b, c));
    adj[b].pb(node(a, c));
  }
  ll ans = prim(1);
  if(ans != -1){
    cout << ans << '\n';
  }else{
    cout << "IMPOSSIBLE\n";
  }
  return 0;
}
