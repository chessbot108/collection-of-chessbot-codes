#include <iostream>
#include <cstring>
#include <algorithm>
#define cont continue
using namespace std;
int dp[550][550], a, b;
int main(){
  cin >> a >> b;
  //a < b < 550
  if(a > b) swap(a, b);
  memset(dp, 0x3f, sizeof(dp));
  for(int i = 0; i<=500; i++) dp[i][i] = 0;
  for(int i = 1; i<=a; i++){
    for(int j = 1; j<=b; j++){
      for(int k = 1; k < j; k++){
        dp[i][j] = min(dp[i][j], min(dp[i][k] + dp[i][j - k], dp[k][i] + dp[j - k][i]) + 1);
      } 
      for(int k = 1; k < i; k++){
        dp[i][j] = min(dp[i][j], min(dp[j][k] + dp[j][i - k], dp[k][j] + dp[i - k][j]) + 1);
      }
    
    }
  }
  cout << min(dp[a][b], dp[b][a]) << endl;
  return 0;
}
