#include <iostream>
#include <algorithm>
using namespace std;
int dp[210000], w[1100], c[1100], n, x;
int main(){
  cin >> n >> x;
  for(int i = 0; i<n; i++) cin >> c[i];
  for(int i = 0; i<n; i++) cin >> w[i];
  
  for(int i = 0; i<n; i++){
    for(int j = x; c[i] < j; j--){
      if(dp[j - c[i]]) dp[j] = max({dp[j - c[i]] + w[i], dp[j], dp[j - 1]});
    }
    dp[c[i]] = max(dp[c[i]], w[i]);
  }
  cout << dp[x];

  return 0;
}
