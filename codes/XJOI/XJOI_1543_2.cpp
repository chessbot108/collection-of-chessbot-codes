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

#define max_v 110
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

vector<int> arr[max_v];
int l[max_v], vis[max_v];
int r[max_v], par[max_v];
vector<int> pre;

int dfs(int x){
  if(par[x] == 0) return x;
  return dfs(par[x]);
}

void bfs(int src){
  queue<int> q;
  q.push(src);
  while(!q.empty()){
    int x = q.front(); q.pop();
    if(vis[x]) cont;
    pre.push_back(x);
    vis[x] = 1;
    for(int i : arr[x]){
      q.push(i);
    }
  }
}

int main(){
	int n;
  scanf("%d", &n);
  for(int i = 1; i<=n; i++){
    int N;
    scanf("%d", &N);
    int a;
    while(N--){
      scanf("%d", &a);
      arr[i].push_back(a);
      par[a] = i;
    }
  }
  int root = dfs(1);
  bfs(root);
  //printf("root: %d\n", root);
  for(int t = 0; t<n; t++){    
    int i = pre[t];
    //printf("%d\n", i);
    l[i] = (arr[i].empty()) ? 0: arr[i][0];
    for(int j = 1; j<arr[i].size(); j++){
      //printf("\t%d\n", arr[i][j]);
      r[arr[i][j - 1]] = arr[i][j];
    }
  }
  printf("%d\n", n);
  for(int i = 1; i<=n; i++){
    printf("%d %d\n", l[i], r[i]);
  }
	return 0;
}

