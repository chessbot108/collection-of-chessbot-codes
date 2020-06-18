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
#define byte_max 0x3f
#define pow_2(n) (1 << n)
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) | 1)
#define RC(n) (((n) << 1) + 2)
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

list<int> tree[max_v];
int sum[max_v], add[max_v];
bool vis[max_v];

void dfs(int cur, int s){
  if(vis[cur]) return ;
  vis[cur] = true;
  s += add[cur];
  sum[cur] = s;
  for(int i : tree[cur])
    dfs(i, s);
}

int main(){
	
  int n, q;
  scanf("%d%d", &n, &q);
  for(int i = 0; i<n - 1; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  while(q--){
    int a, v;
    scanf("%d%d", &a, &v);
    add[a] += v;
  }
  
  dfs(1, 0);

  for(int i = 1; i<=n; i++){
    printf("%d\n", sum[i]);
  }

	return 0;
}

