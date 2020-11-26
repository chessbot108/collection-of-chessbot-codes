#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <list>
#include <queue>
#include <stack>
//#include <unordered_map>
//#include <unordered_set>
#include <functional>

#define max_v 110000
#define int_max 0x3f3f3f3f
#define cont continue
#define pow_2(n) (1 << (n))
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define LOG2(n) ((int)(ceil(log2((n)))))
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int dist[max_v], arr[max_v], strange[max_v];
bool vis[max_v], is[max_v];
vector<pair<int, int>> adj[max_v];
int n, m, k, D = int_max;

struct node{
  int u, dist, steps;
  node(){}
  node(int a, int b, int c){ u = a, dist = b, steps = c; }
  bool operator < (const node& b) const{
    return (dist == b.dist) ? steps < b.steps : dist < b.dist; //helps avoid worst case, choose by edge count AFTER distance
  }
};


bool cmp(int a, int b){
  return rand() < rand(); //maybe randomize it to avoid worse case
}

void dijkstra(int src){
  memset(vis, 0, sizeof(vis));
  memset(dist, 0x3f, sizeof(dist));
  priority_queue<node> pq;
  dist[src] = 0;
  pq.push(node(src, 0, 0));
  while(!pq.empty()){
    node cur = pq.top(); pq.pop();
    int u = cur.u;
    //printf("\treached %d in %d distance and %d steps\n", u, dist[u], cur.steps);
    if(is[u] && u != src){
      //printf("\ti found %d from %d\n", u, src);
      D = min(D, dist[u]);
      break;
    }
    if(dist[u] >= D) break; //might be unnecessary, include for safety
    if(vis[u]) cont;
    assert(dist[u] == cur.dist); //dijkstra depends on this
    vis[u] = true;
    for(auto e : adj[u]){ //.first w, .second v
      int t = dist[u] + e.first;
      if(t < dist[e.second] && t < D){ //t < dist[v], D
        dist[e.second] = t;
        pq.push(node(e.second, t, cur.steps + 1));
      }
    }
  }
}


int main(){
  srand(time(0));
	scanf("%d%d%d", &n, &m, &k);
  for(int i = 0; i<m; i++){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    adj[a].push_back(make_pair(c, b));
    adj[b].push_back(make_pair(c, a));
  }

  for(int i = 1; i<=n; i++) sort(adj[i].begin(), adj[i].end()); //maybe it'll help??
  
  for(int i = 0; i<k; i++){
    scanf("%d", &strange[i]);
    is[strange[i]] = true;
  }
  sort(strange, strange + k, cmp);
  for(int i = 0; i<k; i++){
    //printf("%d\n", strange[i]);
    dijkstra(strange[i]);
  }
  printf("%d\n", D);
	return 0;
}

