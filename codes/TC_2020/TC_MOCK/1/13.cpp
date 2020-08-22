//code by thomas
#include <iostream>
#include <cstdio>
using namespace std;

int dp[1001][101];
int tim[101], val[101];
int t, m;

int main(){
  cin >> t >> m;
  for(int i = 0; i < m; i++){
    cin >> tim[i] >> val[i];
  }
  for(int j = 0; j <= t; j++){
    dp[j][0] = 0; 
  }
  for(int i = 0; i <= m; i++){
    dp[0][i] = 0;
  }
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= t; j++){
      if(tim[i - 1] <= j){
        dp[j][i] = max(val[i - 1] + dp[j - tim[i - 1]][i - 1], dp[j][i - 1]);  
      } else {
        dp[j][i] = dp[j][i - 1];
      }
    }
  }
  cout << dp[t][m] << endl;
  return 0;
}
