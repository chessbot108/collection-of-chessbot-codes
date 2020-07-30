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
#include <utility>

#define max_v 100100
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
#define u second.first
#define v second.second
#define w first
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

vector<pair<int, pair<int, int> > > edges;
int parent[max_v], fib[max_v];
int n, m;

bool cmp(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b){
  return a.w > b.w;
}


int find(int x){
  if(x != parent[x]) parent[x] = find(parent[x]);
  return parent[x];
}

void Union(int x, int y){
  x = find(x), y = find(y);
  if(x == y) return;
  parent[x] = y;
}


void make_DSU(){
  for(int i = 0; i <=n; i++) parent[i] = i;
}


int kruskal(){
  make_DSU();  
  int total = 0, cnt = 0;
  assert(edges.size());
  for(int i = 0; i<edges.size(); i++){
    auto x = edges[i];
    if(find(x.u) != find(x.v)){
      total += x.w; 
      Union(x.u, x.v);
      cnt++;
      //printf("%d: %d %d %d\n", cnt, x.u, x.v, x.w);
    }
  }
  //assert(cnt == n - 1);
  if(cnt != n - 1){
    printf("No");
    exit(0);
  }
  return total;
}

int main(){
  scanf("%d%d", &n, &m);
  if(m == 0){ printf("No"); return 0;}
  for(int i = 0; i<m; i++){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
     edges.push_back(make_pair(c, make_pair(b, a)));
     edges.push_back(make_pair(c, make_pair(a, b)));
  }
   
  sort(edges.begin(), edges.end());
  int mini = kruskal();
  
  sort(edges.begin(), edges.end(), cmp);
  int maxi = kruskal();
  //assert(maxi);
  if(maxi == 0){
    printf("No");
    return 0;
  }
  //printf("%d %d\n", mini, maxi);
  fib[1] = 1;
  fib[0] = 1;
  int i = 2;
  while(true){
    if(fib[i - 1] + fib[i - 2] > m) break;
    fib[i] = fib[i - 1] + fib[i - 2];
    i++;
  }
  bool ans = false;
  for(int j = 0; j<i; j++){
    if(fib[j] >= mini && fib[j] <= maxi) ans = true;
  }

  if(ans) printf("Yes");
  else printf("No");

	return 0;
}

