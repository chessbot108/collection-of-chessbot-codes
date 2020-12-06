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

#define max_v 5100
#define LOGN 50
#define int_max (long long)0x3f3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_1(n) (1 << (n))
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define LOG1(n) ((int)(ceil(log2((n)))))
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

long long graph[max_v][max_v], flow[max_v][max_v];
long long dep[max_v], vis[max_v];
int head[max_v];
vector<int> adj[max_v];
int n, m, src, dest;

bool bfs(){
  queue<int> q;
  q.push(src);
  memset(dep, 0x3f, sizeof(dep));
  memset(head, 0, sizeof(head));
  dep[src] = 0;
  while(!q.empty()){
    int u = q.front(); q.pop();
    if(u == dest) return 1;
    for(int i : adj[u]){
      if(graph[u][i] - flow[u][i] > 0ll && dep[i] > (long long)n + 1){
        dep[i] = dep[u] + 1;
        q.push(i);
      }
    }
  }
  
  return (dep[dest] < (long long)n) ;
}

long long dfs(int u, long long cap){
  long long ans = 0ll;
  if(u == dest || cap == 0ll) return cap;
  for(int i = head[u]; i<adj[u].size(); i++){
    int v = adj[u][i];
    long long C = graph[u][v] - flow[u][v];
    if(u != v && dep[v] == dep[u] + 1 && C > 0ll){
      if(long long sent = dfs(v, min(cap, C))){
        flow[u][v] += sent;
        flow[v][u] -= sent;
        ans += sent;
        cap -= sent;
      }
    }
    if(cap) head[u]++;
    else break;
  }
  if(!ans) dep[u] = int_max;
  return ans;
}

long long dinics(){
  long long tot = 0ll;
  while(bfs()){
    while(true){
      long long sent = dfs(src, int_max);
      tot += (long long)sent;
      if(!sent) break;
    }
  }
  return tot;
}

int main(){
	
  scanf("%d%d", &n, &m);
  src = 1, dest = n;
  while(m--){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if(!c) cont;
    if(!graph[a][b]){
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    graph[a][b] += (long long)c;
    graph[b][a] += (long long)c;
    
  }

  printf("%lld\n", dinics());
	return 0;
}

