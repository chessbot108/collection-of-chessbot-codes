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
  int key, value;
  node(){}
  node(int a, int b){key = a, value = b;}
  bool operator < (const node& b) const{
    return value > b.value;
  }
};

int dist[max_v], n, m, srt[max_v];
list<int> adj[max_v];
pair<int, int> graph[max_v][max_v]; //.first is cost, second is flow
priority_queue<node> pq;
bool vis[max_v];

void dijkstra(int cap){
  memset(dist, 0x3f, sizeof(dist));
  memset(vis, false, sizeof(vis));
  dist[1] = 0;
  pq = priority_queue<node>();
  pq.push(node(1, 0));
  while(!pq.empty()){
    node cur = pq.top(); pq.pop();
    int key = cur.key;
    if(vis[key]) cont;
    if(key == n) break;
    vis[key] = true;
    for(int x : adj[key]){
      if(graph[key][x].second < cap) cont;
      int temp = dist[key] + graph[key][x].first;
      if(dist[x] > temp){
        dist[x] = temp;
        pq.push(node(x, dist[x]));
      }
    }
  }
}



int main(){
	scanf("%d%d", &n, &m);
  for(int i = 0; i<m; i++){
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    graph[a][b] = graph[b][a] = make_pair(c, d);
    adj[a].push_back(b);
    adj[b].push_back(a); //adj matrix but not n^2
    srt[i + 1] = d;
  }

  sort(srt + 1, srt + m + 1);
  long long tot = 0;
  for(int i = 1; i<=m; i++){
    dijkstra(srt[i]);
    //printf("%d %d\n", srt[i], dist[n]);
    tot = max(tot, (long long)(srt[i] * 1e6) / (long long)(dist[n]));
  }
  printf("%lld\n", tot);

	return 0;
}

