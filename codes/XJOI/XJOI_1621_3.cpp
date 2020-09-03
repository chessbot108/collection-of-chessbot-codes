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

#define max_v 100100
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

//hoping to get 8 test cases with a TLE sol
int dp[max_v][30], n, m, k, pre[max_v][30], cost[max_v][30]; //pre for prefix sums;
int arr[max_v], best[max_v], dist[50][50]; //floyd on this
char str[max_v];

void floyd(){
  for(int i = 1; i<=m; i++){
    for(int j = 1; j<=m; j++){
      for(int k = 1; k<=m; k++){
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
      }
    }
  }

}

int main(){
	scanf("%d%d%d%s", &n, &m, &k, str);
  for(int i = 0; i<n; i++) arr[i] = str[i] - 'a';
  for(int i = 1; i<=m; i++)
    for(int j = 1; j<=m; j++)
      scanf("%d", &dist[i][j]);
  floyd();
  
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m; j++){
      cost[i][j] = dist[arr[i - 1] + 1][j];
      pre[i][j] = pre[i - 1][j] + cost[i][j];
    }
  }
    
  memset(dp, 0x3f, sizeof(dp));
  memset(best, 0x3f, sizeof(best));
  best[0] = 0;
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m; j++){
      dp[i][j] = min(dp[i][j], dp[i - 1][j] + cost[i][j]);
      if(i >= k){
        dp[i][j] = min(dp[i][j], pre[i][j] - pre[i - k][j] + best[i - k]);
      }
      //printf("%d, %d -> %d\n", i, j, dp[i][j]);
      best[i] = min(best[i], dp[i][j]);
    }
  }
  
  printf("%d\n", best[n]);

	return 0;
}

