//code by weiming

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

int dist[max_v], n;
bool vis[max_v];
list<int> arr[max_v];

void dfs(int cur, int dis){
  if(vis[cur]) return ;
  dist[cur] = dis;
  vis[cur] = true;
  for(int x : arr[cur])
   dfs(x, dis + 1);
}


int call(int src){
  memset(vis, 0, sizeof(vis));
  memset(dist, 0, sizeof(dist));
  dfs(src, 1);
  int ind, maxi = -1;
  for(int i = 1; i<=n; i++){
    if(maxi < dist[i]){
      maxi = dist[i];
      ind = i;
    }
  }
  return ind;
}


int main(){
  
  scanf("%d", &n);
  for(int i = 0; i<n - 1; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    arr[a].push_back(b);
    arr[b].push_back(a);
  }
  int ind = call(call(1));
  printf("%d", dist[ind] - 1);
  
	return 0;
}

