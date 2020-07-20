//removed half my header since...
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <list>
#define max_v 1100
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

list<int> graph[max_v], r_graph[max_v];
int rep[max_v], pre[max_v], ind = 0, n, m; //use rep as vis array
bool vis[max_v];

void dfs_1(int u){
  if(vis[u]) return ;
  vis[u] = true;
  for(int v : r_graph[u])
    dfs_1(v);
  pre[ind++] = u;
}

void dfs_2(int u, int r){
  if(rep[u]) return ;
  rep[u] = r;
  for(int v : r_graph[u])
    dfs_2(v, r);
}

void make_scc(){
  for(int i = 1; i<=n; i++)
    dfs_1(i);
  
  while(~ind){
    int t = pre[ind]; ind--;
    dfs_2(t, t);
  }

} 

int main(){
	scanf("%d%d", &n, &m);
  for(int i = 0; i<m; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    graph[a].push_back(b);
    r_graph[b].push_back(a);
  } 

  make_scc();
  
  for(int i = 1; i<=n; i++){
    printf("%d -> %d\n", i, rep[i]);
  }

	return 0;
}

