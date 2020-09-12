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

#define max_v 210000
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
int ans[max_v], n;

int dfs(int u){
  for(int x : arr[u]){
    ans[u] += dfs(x) + 1;
  }
  return ans[u];
}

int main(){
  scanf("%d", &n);
  for(int i = 2; i<=n; i++){
    int a;
    scanf("%d", &a);
    arr[a].push_back(i);
  }
	dfs(1);
  for(int i = 1; i<=n; i++){
    printf("%d ", ans[i]);
  }
	return 0;
}

