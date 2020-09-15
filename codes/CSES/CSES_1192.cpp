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

bool vis[max_v][max_v];
char str[max_v][max_v];
int n, m;

void dfs(int x, int y){
  if(x < 0 || y < 0 || x >= n || y >= m || vis[x][y]) return ;
  vis[x][y] = true;
  dfs(x + 1, y);
  dfs(x - 1, y);
  dfs(x, y + 1);
  dfs(x, y - 1);
}


int main(){
	scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++){
    scanf("%s", str[i]);
    assert(strlen(str[i]) == m);
    for(int j = 0; j<m; j++){
      vis[i][j] = (str[i][j] == '.') ? false : true;
    }
  }
  int cnt = 0;
  for(int i = 0; i<n; i++){
    for(int j = 0; j<m; j++){
      if(!vis[i][j]) cnt++;
      dfs(i, j); //lazy coding be like
    }
  }
  printf("%d\n", cnt);
	return 0;
}

