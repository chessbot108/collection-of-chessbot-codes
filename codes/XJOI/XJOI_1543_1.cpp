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

#define max_v 11000
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
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 0; i<=n; i++) parent[i] = i;
  while(m--){
    int q, a, b;
    scanf("%d%d%d", &q, &a, &b);
    if(q == 1){
      Union(a, b);
    }else{
      if(find(a) == find(b)){
        puts("Y");
      }else{
        puts("N");
      } 
    }
  }
	return 0;
}

