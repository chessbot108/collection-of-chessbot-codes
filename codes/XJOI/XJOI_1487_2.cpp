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
//this is n log n. please never use thing for legit topo sort. i only used this since it gets around the "lexi smallest" thing
bool gr[max_v][max_v];

int n, m, ind = 0;
int arr[max_v];
bool vis[max_v];

void dfs(int cur){
  if(vis[cur]) return;
  vis[cur] = true;
  for(int i = 1; i<=n; i++){
    if(gr[cur][i])
      dfs(i);
  }
  arr[ind++] = cur;
    
}

int main(){
	int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 0; i<m; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    gr[a][b] = true;
  }

  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n; j++){
      if(i != j && !gr[i][j] && i < j){
        gr[i][j] = true;
      }
    } 
  }

  for(int i = 1; i<=n; i++){
    if(!vis[i]) dfs(i);  
  }
  
  for(int i = 0; i<n; i++){
    printf("%d ", arr[i]);
  }

	return 0;
}

