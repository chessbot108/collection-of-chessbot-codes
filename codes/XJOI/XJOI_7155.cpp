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
 
#define max_v 120
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
/**
 * weird dp
 * i think i can knapsack on the value for the answer
 * here is the dp equation
 * dp[i][j] -> the min WEIGHT acchievable with i elemtents considered and the value at j
 * dp[i][j] = min(dp[i][j], dp[i - 1][j - value[i]] + weight[i])
**/
int dp[max_v][max_v * max_v];
int w[max_v], v[max_v];
int main(){
  int n, W;
  scanf("%d%d", &n, &W);
  for(int i = 1; i<=n; i++){
    scanf("%d%d", &w[i], &v[i]);
  }
  memset(dp, 0x3f, sizeof(dp));
  for(int i = 0; i<n; i++) dp[i][0] = 0;
  for(int i = 1; i<=n; i++){
    for(int j = 1e4 + 10; j >= 0; j--){
      dp[i][j] = dp[i - 1][j];
      if(j - v[i] < 0) cont; //FIX: don't use break or else line 64 won't run
      dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
    }
  }
  int maxi = -1;
  for(int i = 0; i<=1e4 + 10; i++){
    if(dp[n][i] <= W) maxi = max(maxi, i);
  }
  printf("%d", maxi);
  return 0;
}
