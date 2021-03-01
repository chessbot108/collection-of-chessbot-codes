#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <utility>


const int int_max = 0x3f3f3f3f, max_v = 330;
using namespace std;

int dp[max_v][max_v], arr[max_v];
int n;

int main(){
	cin.tie(0) -> sync_with_stdio(0);
  cin >> n;

  for(int i = 1; i<=n; i++){
    cin >> arr[i];
  }

  memset(dp, 60, sizeof(dp));
  int L = 1;
  for(int i = 1; i<=n; i++){
    dp[i][i + 1] = 1;
  }

  //dp[i][j] = min strokes needed to paint [i, j)
  //min of seeing i can surround it, and all disjoint segments
  for(int len = 1; len <= n; len++){
    for(int i = 1; i + len + 1 <= n + 1; i++){
      int j = i + len + 1;
      
      int &ans = dp[i][j];
      //each segment is:
      //1) the extension of a smaller segment
      if(arr[i] == arr[i + 1]) ans = min(ans, dp[i + 1][j]);
      if(arr[j - 1] == arr[j - 2]) ans = min(ans, dp[i][j - 1]);
      //2) a smaller segment with a layer of paint
      if(arr[i] == arr[j - 1]) ans = min(ans, dp[i + 1][j - 1] + 1);
      //3) two disjoint segments linked together
      for(int k = i + 1; k<j; k++){
        assert(dp[i][k] <= n && dp[k][j] <= n);
        ans = min(ans, dp[i][k] + dp[k][j]);
      }
      assert(ans <= n);
    }
  }
  /**
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n + 1; j++){
      //printf("%6d ", dp[i][j] >= max_v ? 0 : dp[i][j]);
    }
    //puts("");
  }
  **/
  cout << dp[1][n + 1] << endl;


	return 0;
}
/**
 * try bashing
 * ll overflow
 * mod negatives
 * debug!!! assert!!!
 * dont forget to take all input
 * time matters!!!
 * dont start coding until you know how to solve it
 * have fun kek
**/

