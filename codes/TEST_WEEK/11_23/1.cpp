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

#define max_v 2500
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

int a[max_v * 2], b[max_v * 2], res[max_v], vis[max_v];
vector<int> adj[max_v * 2];

struct node{
  int u, steps;
  node(){}
  node(int a, int b){u = a, steps = b;}
};

int bfs(int src){
  memset(vis, false, sizeof(vis));
  //printf("%d\n", src);
  queue<node> q;
  q.push(node(src, 1));
  while(!q.empty()){
    node cur = q.front(); q.pop();
    int u = cur.u;
    //printf("\t%d %d\n", u, cur.steps);
    if(res[u]) return cur.steps;
    vis[u] = 1;
    for(int v : adj[u]){
      if(!vis[v]) q.push(node(v, cur.steps + 1));
    }
  }
  return -1;
}


int main(){
  int n, D;
  scanf("%d%d", &n, &D);
  for(int i = 0; i<n; i++){
    scanf("%d%d", &a[i], &b[i]);
    if(b[i] == 0) res[i] = true;
  }
  for(int i = 0; i<n; i++){
    scanf("%d%d", &a[i + n], &b[i + n]);
    if(a[i + n] == 0) res[i + n] = true;
  }
  
  for(int i = 0; i<n; i++){
    for(int j = n; j<n*2; j++){
      if(b[i] <= a[j] && a[j] <= b[i] + D) adj[i].push_back(j);
      if(b[j] <= a[i] && a[i] <= b[j] + D) adj[j ].push_back(i);
    }
  }

  //for(int i = 0; i<n*2; i++){
    //printf("%d\n\t", i);
    //for(int v : adj[i]) printf("%d ", v); puts("");
  //}

  for(int i = 0; i<n; i++){
    printf("%d\n", bfs(i));
  }
	return 0;
}

