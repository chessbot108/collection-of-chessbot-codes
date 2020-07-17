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

list<int> arr[max_v];

bool vis[max_v];

void dfs(int cur){
  if(vis[cur]) return ;
  vis[cur] = true;
  for(int x : arr[cur])
    dfs(x);
}


int main(){
	int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 0; i<m; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    arr[a].push_back(b);
    arr[b].push_back(a);
  }
  
  int cnt = 0;
  for(int i = 1; i<=n; i++){
    if(!vis[i]){
      dfs(i);
      cnt++;
    }
  }
  printf("%d\n", cnt);

	return 0;
}

