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
#define LOGN 50
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
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

struct node{
  int u, dist;
  node(){}
  node(int a, int b){ u = a, dist = b; }
  bool operator < (const node& b) const{  
    return dist > b.dist;
  }
};

//my alg is 100% correct so i prolly misunderstood the problem. ;-;
int dist[max_v], par[max_v], arr[max_v], hay[max_v], vis[max_v], state[max_v], tmp[max_v];
priority_queue<node> pq;
int n, m, k;

list<pair<int, int> > adj[max_v];

void dijkstra(int src, int trunct, bool R){ //scuffed af, but R is too determine which dijkstra i'm using
  memset(dist, 0x3f, sizeof(dist));
  
  dist[src] = 0;
  pq = priority_queue<node>();
  pq.push(node(src, 0));
  printf("src at %d\n", src);
  while(!pq.empty()){
    node top = pq.top(); pq.pop();
    int u = top.u;
    if(!R && top.dist * 2 > trunct) break;
    if(vis[u]) cont;
    if(R) state[u] = max(tmp[u], state[u]);
    vis[u] = 1;
    dist[u] = 0; //resetting dist lazily
    printf("\tdist[%d] * 2 == %d <= %d\n\tstate[%d] = %d\n", u, top.dist, trunct, u, state[u]);
    for(auto e : adj[u]){
      int v = e.first, w = e.second;
      int temp = top.dist + w;
      printf("\t\tto get to %d, dist is min of %d and %d + %d\n", v, dist[v], top.dist, w);
      if(temp < dist[v] && !vis[v]){
        dist[v] = temp;
        tmp[v] = state[u];
        pq.push(node(v, dist[v]));
      }else if(temp == dist[v]){
        tmp[v] = max(state[u], tmp[v]);
      }
    }
  }

}


int main(){
	scanf("%d%d%d", &n, &m, &k);
  for(int i = 0; i<m; i++){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    adj[a].push_back(make_pair(b, c));
    adj[b].push_back(make_pair(a, c));
  }

  for(int i = 0; i<k; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    dijkstra(a, b, 0);
  }
    
  for(int i = 1; i<=n; i++) state[i] = vis[i];
  for(int i = 1; i<=n; i++) printf("%d\n", vis[i]); puts("");
  memset(vis, 0, sizeof(vis));
  memset(tmp, 0, sizeof(tmp));
  
  dijkstra(n, 0, 1);

  for(int i = 1; i<n; i++){
    printf("%d\n", state[i]);
  }
	
  return 0;
}

