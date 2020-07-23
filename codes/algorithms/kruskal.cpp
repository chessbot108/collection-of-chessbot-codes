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
//problem specific

#define w first
#define u second.first
#define v second.second

using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}


vector<pair<int, pair<int, int>>> edges;
int par[max_v];

int find(int n){
  if(n != par[n]) par[n] = find(par[n]);
  return par[n];
}

void Union(int a, int b){
  a = find(a), b = find(b);
  if(a == b) return ;
  par[a] = b;
}
  

int kruskal(){
  sort(edges.begin(), edges.end());
  int total = 0;
  for(auto e : edges){
    if(find(e.u) != find (e.v)){
      total += e.w;
      Union(e.u, e.v);
    }
  }
  return total;
}


int main(){
	int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 0; i<m; i++){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    edges.push_back(make_pair(c, make_pair(a, b)));
  }
  printf("%d\n", kruskal());
	return 0;
}

