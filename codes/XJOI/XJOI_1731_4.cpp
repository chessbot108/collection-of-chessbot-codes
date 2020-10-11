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

#define max_v 1100
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
  int dist, pre, u;
  node(int a, int b, int c){
    dist = a, pre = b, u = c;
  }
  bool operator < (const node& b) const{
    return (dist == b.dist) ? pre > b.pre : dist > b.dist;
  }
};

int dist[max_v], pre[max_v], vis[max_v];
int n, m, s, d;

vector<pair<int, int>> adj[max_v];
priority_queue<node> pq;
void dijkstra(){
  memset(dist, 120, sizeof(dist));
  pq.push(node(0, -1, d));
  dist[d] = 0;
  
  while(!pq.empty()){
    node cur = pq.top(); pq.pop();
    int u = cur.u;
    if(vis[u]) cont;
    pre[u] = cur.pre;
    vis[u] = 1;

    for(auto e : adj[u]){
      if(dist[e.first] >= dist[u] + e.second){
        dist[e.first] = dist[u] + e.second;
        pq.push(node(dist[e.first], u, e.first));
      }
    } 

  }

}


int main(){
	scanf("%d%d%d%d", &s, &d, &n, &m);
  for(int i = 0; i<m; i++){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    adj[a].push_back(make_pair(b, c));
    adj[b].push_back(make_pair(a, c));
  }
  dijkstra();
  printf("%d\n", dist[s]);
  for(int i = s; ~i; i = pre[i]){
    printf("%d ", i);
  }
	return 0;
}

