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
#include <unordered_map>
#include <unordered_set>
#include <functional>

#define max_v 110000
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)

using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

class DSU{
  int parent[max_v];
  public:
    DSU(int V){
      for(int i = 0; i<=V; i++){
        parent[i] = i;
      }
    }
    
    int find(int n){
      if(parent[n] != n) parent[n] = find(parent[n]);
      return parent[n];
    }
    
    void Union(int a, int b){
      a = find(a);
      b = find(b);
      if(a == b) return ;
      if(b < a) swap(a, b);
      parent[b] = a;
    }

};

vector<pair<int, int>> edges;

int max_edges(){
  DSU D((int)1e5);
  int tot = 0;
  for(int i = 0; i<edges.size(); i++){
    int u = edges[i].first, v = edges[i].second;
    if(D.find(u) != D.find(v)){
      tot++;
      D.Union(u, v);
    }
  }
  return tot;
}



int main(){
	int a, b;
  while(scanf("%d", &a) != EOF){
    if(a != -1){
      scanf("%d", &b);
      edges.push_back(make_pair(a, b));
    }else{
      printf("%d\n", edges.size() - max_edges());
      edges.clear();
    }

  }

	return 0;
}

