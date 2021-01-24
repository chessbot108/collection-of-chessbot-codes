#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <string>
#define max_v 51000
#define ll long long
#define int_max 0x3f3f3f3f
#define cont continue
#define pow_2(n) (1 << (n))
#define pb push_back
#define w(i, j) ((ll)abs(i - j))
using namespace std;

struct node{
  int key;
  ll val;
  node(){}
  node(int a, ll b){ key = a, val = b; }
  bool operator < (const node& b) const{
    return val > b.val;
  }

};

int com[110][110];
int arr[max_v], occ[110], vis[max_v];
ll dist[max_v];
vector<int> adj[max_v];
priority_queue<node> pq;
int n, k;
string a;
void dijkstra(){
  int src = 1, dest = n;
  memset(dist, 0x3fll, sizeof(dist));
  dist[src] = 0ll;
  pq.push(node(src, 0ll));
  while(!pq.empty()){
    node cur = pq.top(); pq.pop();
    int u = cur.key;
    if(u == dest) break;
    if(vis[u]) cont;
    vis[u] = true;
    for(int v : adj[u]){
      if(dist[u] + w(u, v) < dist[v]){
        dist[v] = dist[u] + w(u, v);
        pq.push(node(v, dist[v]));
      }
    }
  }
}


int main(){
  cin.tie(NULL); ios_base::sync_with_stdio(0);
	cin >> n >> k;
  for(int i = 1; i<=n; i++) cin >> arr[i];
  for(int i = 1; i<=k; i++){
    cin >> a;
    for(int j = 1; j<=k; j++) com[i][j] = a[j - 1] - '0';
  }
  /**
  cout << "input done" << endl;
  for(int i = 1; i<=k; i++){
    for(int j = 1; j<=k; j++)
      cout << com[i][j];
    cout << endl;
  }
  **/
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=k; j++){
      //if(arr[i] == j && occ[j] != n) cont;
      if(com[arr[i]][j] && occ[j]) adj[i].pb(occ[j]);
    }
    occ[arr[i]] = i;
  }
  memset(occ, 0, sizeof(occ));
 
  for(int i = n; i >= 1; i--){
    for(int j = 1; j<=k; j++){
      //if(arr[i] == j && occ[j] != n) cont;
      if(com[arr[i]][j] && occ[j]) adj[i].pb(occ[j]);
    }
    occ[arr[i]] = i;
  }
  /**
  cout << "sweeping done" << endl;
  for(int i = 1; i<=n; i++){
    cout << "adj[" << i << " " << arr[i] << "] : " ;
    for(int v : adj[i]) cout << "(" << v << ", " << arr[v] << ") "; cout << endl;
  }
  **/
  dijkstra();
  if(dist[n] == 0x3f3f3f3f3f3f3f3fll) cout << -1 << endl;
  else cout << dist[n] << endl;
	return 0;
}

