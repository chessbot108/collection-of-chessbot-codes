//code by me

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
const int MX = 1e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
  freopen((file_name+".in").c_str(), "r", stdin);
  freopen((file_name+".out").c_str(), "w+", stdout);
}
struct node{
  int u, w;
  node(){}
  node(int a, int b){ u = a, w = b;}
  bool operator < (const node& b) const{
    return w < b.w; //skewed dijkstra's
  }
};
pbenq<node> pq;
int dist[MX], vis[MX], n, m, q, st[MX];
vector<int> adj[MX];
vector<pii> ans;
void dijkstra(){
  for(int i = 2; i<=n; i++){
    if(dist[i] > 0){
      pq.push(node(i, dist[i]));
    }
  }

  while(!pq.empty()){
    node cur = pq.top(); pq.pop();
    int u = cur.u;
    if(vis[u]) cont;
    vis[u] = 1;
    //moo("\t%d %d\n", u, dist[u]);
    for(int v : adj[u]){
      if(dist[v] < dist[u]/2 && v != 1 && st[v] != 1){
        dist[v] = dist[u]/2;
        pq.push(node(v, dist[v]));
      }
    }
  }
  

}

bool cmp(const pii& a, const pii& b){
  return (a.first > b.first) || (a.first == b.first && a.second < b.second);
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m >> q;
  for(int i = 0; i<m; i++){
    int a, b; cin >> a >> b;
    dist[a] = b;
    st[a] = 1;
  }
  for(int i = 0; i<q; i++){
    int a, b; cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  dijkstra();
  for(int i = 2; i<=n; i++) ans.pb(mp(dist[i], i));
  sort(ans.begin(), ans.end(), cmp);
  for(int i = 0; i<n-1; i++){
    moo("%d %d\n", ans[i].second, ans[i].first);
  }
  return 0;
}


