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

int pre[max_v * 2], trav[max_v * 2], par[max_v * 2], height[max_v * 2], occ[max_v*2], ind = 0, pre_ind = 0;
int d[max_v * 2][50], res[max_v * 2][50];
bool vis[max_v];
list<int> adj[max_v];


void dfs(int u, int dep){
  if(vis[u]) return ;
  pre[++pre_ind] = u;
  vis[u] = true;
  height[u] = dep;
  for(int v : adj[u]){
    dfs(v, dep + 1);
    trav[ind] = u;
    occ[u] = ind++;
  }
}

void lca_precomp(){
  trav[0] = 1;
  ind = 1;
  dfs(1, 0);
  for(int i = 0; i<ind; i++){
    d[i][0] = height[trav[i]];
    res[i][0] = trav[i];
  }
  for(int i = 1; i<=LOG2(ind); i++){
    for(int j = 0; j<ind; j++){
      if(d[j][i - 1] < d[j + pow_2(i - 1)][i - 1]){
        d[j][i] = d[j][i - 1];
        res[j][i] = res[j][i - 1];
      }else{
        d[j][i] = d[j + pow_2(i - 1)][i - 1];
        res[j][i] = res[j + pow_2(i - 1)][i - 1];
      }
    }
  }   
}

int LCA(int u, int v){
  if(u == v) return u;
  if(occ[u] < occ[v]) swap(u, v);
  int k = log2(occ[u] - occ[v]);
  u = occ[u] + 1, v = occ[v];
  return (d[v][k] < d[u - pow_2(k)][k]) ? res[v][k] : res[u - pow_2(k)][k];
}


int main(){
	int n, q;
  memset(d, 0x3f, sizeof(d));
  memset(height, 0x3f, sizeof(height));
  scanf("%d%d", &n, &q);
  for(int i = 1; i<n; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  lca_precomp();
  //printf("finish precomp");
  while(q--){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", LCA(a, b));
  }

	return 0;
}

