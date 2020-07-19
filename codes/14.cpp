//code by weiming
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

#define max_v 210000
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
  long double dist;
  int key;
  node(){}
  node(long double a, int b){
    dist = a, key = b;
  }

  bool operator < (const node& b) const{
    return dist > b.dist;
  }
  
};


struct edge{
  int u, v;
  long double w;
  edge(){}
  edge(int a, int b, double c){
    u = a, v = b;
    w = c;
  }
  bool operator < (const edge& b) const{
    return u < b.u;
  }
}edges[max_v];

int n, m;
int U[max_v];
long double dist[max_v];
bool vis[max_v];

int get_ind(int key){
  return lower_bound(U, U + m*2, key) - &U[0];
}

long double dijkstra(int src, int dest){
  for(int i = 0; i<=n; i++) dist[i] = (long double) 1e9;
  node S = node((long double)100, dest);
  dist[dest] = 100;

  priority_queue<node>pq;
  pq.push(S);

  while(!pq.empty()){
    node cur = pq.top(); pq.pop();
    int key = cur.key;
    long double d = cur.dist;
    //`printf("%d %.3Lf\n", key, d);
    if(vis[key]) cont;
    vis[key] = true;
    for(int i = get_ind(key); i < m*2; i++){
      if(edges[i].u != key) break;
      long double te = (long double)(100)* d/(long double)(100 - edges[i].w);
      //printf("%.3Le\n", te);
      if(te < dist[edges[i].v]){
        dist[edges[i].v] = te;
        pq.push(node(te, edges[i].v));
      }
    }
  }
  
  return dist[src];
}



int main(){
  scanf("%d%d", &n, &m);
  for(int i = 0; i<m; i++){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    edges[i*2] = edge(a, b, c);
    edges[i*2 + 1] = edge(b, a, c);
  }
  
  sort(edges, edges + m * 2);

  for(int i = 0; i<m * 2; i++) U[i] = edges[i].u;
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%.8Lf", dijkstra(a, b));
  


	return 0;
}

