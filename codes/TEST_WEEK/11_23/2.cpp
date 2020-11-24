//XJOI 1636 2
//11/23 test 2
//barn painting gold


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

const long long MOD = 1e9 + 7;


bool vis[max_v];
int arr[max_v];
int n, k;
vector<int> adj[max_v];
long long dp[max_v][10];


long long dfs(int u, int p, int c){//current node, parent, color
  //printf("%d from %d colored as %d\n", u, p, c);
  if(dp[u][c]) return dp[u][c];
  if(arr[u] && arr[u] != c) return 0ll;
  long long ans = 1ll;
  for(int v : adj[u]){
    if(v == p) cont;
    long long tmp = 0ll;
    for(int i = 1; i<=3; i++) if(i != c) tmp += dfs(v, u, i);
    (ans *= (tmp%MOD)) %= MOD;
  }
  //printf("node %d as %d == %d\n", u, c, ans);
  return dp[u][c] = ans;
}


int main(){
	scanf("%d%d", &n, &k);
  for(int i = 1; i<n; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i = 0; i<k; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    arr[a] = b;
  }
    
  adj[0].push_back(1);
  printf("%lld\n", dfs(0, -1, 0));
	return 0;
}

