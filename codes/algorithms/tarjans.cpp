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

bool vis[max_v], st[max_v];
int low[max_v], pre[max_v], dfn[max_v], rep[max_v], n, m, ind = 0, st_ind = 0;
list<int> adj[max_v];

void dfs(int u){
  if(vis[u]) return ;
  dfn[u] = low[u] = ind++;
  pre[st_ind++] = u;
  vis[u] = st[u] = true;
  for(int v : adj[u]){
    if(!vis[v]){
      dfs(v);
      low[u] = min(low[u], low[v]);
    }else if(st[v]){
      low[u] = min(low[u], dfn[v]);
    }
  }

  if(dfn[u] == low[u]){
      while(~st_ind){
        int v = pre[st_ind--];
        st[v] = false;
        rep[v] = u;
        if(v == u) break;
      }
  }

}

void tarjans(){
  for(int i = 0; i<n; i++)
    dfs(i);
}



int main(){
	
  scanf("%d%d", &n, &m);
  for(int i = 0; i<m; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
  }
  tarjans(); 
  for(int i = 1; i<=n; i++){
    printf("%d-> %d\n", i, rep[i]);
  }

	return 0;
}

