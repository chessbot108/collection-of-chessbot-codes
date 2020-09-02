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

#define max_v 2100
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


list<int> adj[max_v];
long long arr[max_v], dp[max_v][max_v];
long long c;
int n, m;

int main(){
  scanf("%d%d%lld", &n, &m, &c);
  for(int i = 1; i<=n; i++){
    scanf("%lld", &arr[i]);
  }
  
  for(int i = 0; i<m; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    adj[b].push_back(a); //rev adj, since each nodes points to its parents
  }

  memset(dp, 0xBfll, sizeof(dp));

  dp[0][1] = 0ll;
  for(int i = 1; i<max_v/2; i++){
    for(int j = 1; j<=n; j++){
      for(int x : adj[j]){
        dp[i][j] = max(dp[i - 1][x] + arr[j], dp[i][j]);
      }
      //printf("dp[%d][%d] = %lld\n", i, j, dp[i][j]);
    }
  }
  long long ans = 0ll;
  for(int i = 0; i<max_v/2; i++){
    //printf("%d %d %d %d\n", i, dp[i][1], c*i*i, dp[i][1] - c*i*i);
    ans = max(ans, dp[i][1] - (c * (long long)(i*i)));
  }
  printf("%lld\n", ans);
	return 0;
}


