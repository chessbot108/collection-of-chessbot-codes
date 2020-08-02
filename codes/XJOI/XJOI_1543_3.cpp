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
#define u second.second
#define v second.first
#define w first
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

vector<pair<int, pair<int, int> > > edges;
int parent[max_v];
int find(int x){
  if(parent[x] != x) parent[x] = find(parent[x]);
  return parent[x];
} 

void Union(int a, int b){
  a = find(a), b = find(b);
  parent[a] = b;
}


int main(){
	int n;
  scanf("%d", &n);
  for(int i = 0; i<=n; i++) parent[i] = i;
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n; j++){
      int w;
      scanf("%d", &w);
      if(w) edges.push_back(make_pair(w, make_pair(i, j)));
    }
  }
  int m;
  scanf("%d", &m);
  for(int i = 0; i<m; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    Union(a, b);
  }
  int total = 0;
  sort(edges.begin(), edges.end());
  for(int i = 0; i<edges.size(); i++){
    if(find(edges[i].u) != find(edges[i].v)){
      total += edges[i].w;
      Union(edges[i].u, edges[i].v);
    }
  }
  printf("%d", total);
	return 0;
}

