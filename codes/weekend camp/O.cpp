//escape plan
//https://zoj.pintia.cn/problem-sets/91827364500/problems/91827370531
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
#define init(arr, val, sz) memset(arr, val, (sz + 2) * sizeof(arr[0]))
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define tern(a, b, c) ((a) ? (b) : (c))
//the following ones give off usaco vibes
#define pbenq priority_queue
#define moo printf
#define oom scanf
#define mool puts("") 
#define loom getline

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
  node(int a, int b){ u = a, w = b; }
  bool operator < (const node& b) const{
    return w > b.w;
  }
};

vector<pii> adj[MX];
int dist[MX], en[MX], blo[MX], vis[MX], fin[MX];
int n, m, k;

pbenq<node> pq; //OTZ OTZ OTZ

int dijkstra(){
  pq = pbenq<node>();
  init(dist, 0x3f, n);
  init(vis, 0, n);
  for(int i = 1; i<=n; i++){
    if(en[i]){
      pq.push(node(i, 0));
      dist[i] = 0;
    }
  }
  while(!pq.empty()){
    node cur = pq.top(); pq.pop(); 
    //moo("%d %d\n", cur.u, cur.w);
    int u = cur.u, d = cur.w;
    if(blo[u] && !en[u]){
      blo[u]--; cont;
    }
    if(u == 1) return d;
    if(vis[u]) cont;
    vis[u] = 1;
    for(const auto& e : adj[u]){
      int v = e.first, t = e.second + d;
      //if(dist[v] > t){
        //dist[v] = t;
        pq.push(node(v, t));
      //}
    }
  }
  return -1;
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--){
    cin >> n >> m >> k;
    for(int i = 0; i<=n; i++) adj[i].clear();
    init(en, 0, n);
    init(blo, 0, n);
    for(int i = 0; i<k; i++){
      int a; cin >> a;
      en[a]++;
    }
    for(int i = 1; i<=n; i++) cin >> blo[i];
    for(int i = 0; i<m; i++){
      int a, b, c; cin >> a >> b >> c;
      adj[a].pb(mp(b, c));
      adj[b].pb(mp(a, c));
    }
    moo("%d\n", dijkstra());
  } 
	return 0;
}


