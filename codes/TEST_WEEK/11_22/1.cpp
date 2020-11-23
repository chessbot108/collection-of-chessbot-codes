//XJOI 1634 1
//xcamp test 11 1
//mootube gold


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
#define int_max 0x3f3f3f3f
#define cont continue
#define pow_2(n) (1 << (n))
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define LOG2(n) ((int)(ceil(log2((n)))))
//problem specific
#define rel first.first
#define node first.second
#define index second
#define v first
#define w second
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}
//ds's needed: tree, DSU, offline queries
int rank[max_v], size[max_v], ans[max_v], par[max_v], vis[max_v];
vector<pair<int, int>> adj[max_v], adj2[max_v];

vector<pair<pair<int, int>, int>> query;
int n, q;

int find(int x){
  if(x != par[x]) par[x] = find(par[x]);
  return par[x];
}

void Union(int a, int b){
  a = find(a), b = find(b);
  if(a == b) return ;
  par[b] = a;
  size[a] += size[b];
}

int bfs(int src, int k){
  src = find(src);
  queue<int> q;
  q.push(src);
  //printf("bfs from node %d with relevance %d\n", src, k);
  while(!q.empty()){
    //printf("\t%d\n", q.front());
    int u = q.front(); q.pop();
    if(vis[find(u)]) cont;
    vis[find(u)] = true;
    for(auto e : adj[find(u)]){
      if(e.w < k){
        adj2[src].push_back(e);
        cont;
      }
      q.push(e.v);
    }
    Union(src, find(u));

  }

  adj[src] = adj2[src];
  vis[src] = false;
  adj2[src].clear();
  return size[src] - 1;
}


int main(){
  scanf("%d%d", &n, &q);
  for(int i = 1; i<n; i++){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    adj[a].push_back(make_pair(b, c));
    adj[b].push_back(make_pair(a, c));
  }
  for(int i = 0; i<q; i++){
    int q, k;
    scanf("%d%d", &k, &q);
    query.push_back(make_pair(make_pair(1e9 - k, q), i));
  }
  //printf("input done\n");
  for(int i = 0; i<=n; i++){
    par[i] = i;
    size[i] = 1;
  }
  
  sort(query.begin(), query.end());

  for(auto q : query){
    int u = q.node, k = 1e9 - q.rel;
    ans[q.index] = bfs(u, k);
  }
  for(int i = 0; i<q; i++){
    printf("%d\n", ans[i]);
  }
	return 0;
}

