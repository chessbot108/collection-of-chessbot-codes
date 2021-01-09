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


//define chains
//define data structure on each chain
//precompute each chain



vector<pair<int, int> > adj[max_v];
int par[max_v], ord[max_v], sub[max_v], head[max_v], heavy[max_v], dep[max_v], trav;
int n, q, ind = 0;
int dfs(int u, int p, int d){
  dep[u] = d;
  par[u] = p;
  heavy[u] = -1;
  int maxi = 0, ind = -1, ans = 0;
  for(int i = 0; i<adj[u].size(); i++){
    int v = adj[u][i].first, w = adj[u][i].second;
    if(v == p) cont;
    ans += dfs(v, u, d + 1);
    if(maxi < sub[v]){
      maxi = sub[v], ind = i;
      heavy[u] = v;      
    } 
  }
    
  if(~ind) swap(adj[u][ind], adj[u][0]);
  return sub[u] = ans + 1;
}



void dfs2(int u, int p, int s){
  trav[ind] = u;
  ord[u] = ind++; //ord[trav[i]] == i

}


int main(){
	scanf("%d%d", &n, &q);
  for(int i = 1; i<n; i++){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    adj[a].push_back(make_pair(b, c));
    adj[b].push_back(make_pair(a, c));
  }
  dfs(1, 0, 0);
  for(int i = 1; i<=n; i++){
    printf("%d: %3d %3d %3d %3d\n", i, dep[i], heavy[i], par[i], sub[i]);
  }
	return 0;
}

