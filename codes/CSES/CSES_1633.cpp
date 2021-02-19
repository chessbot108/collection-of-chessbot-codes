#include <iostream>
#define add(a, b) ((a%mod + b%mod)%mod)
using namespace std;
const int mod = 1e9 +7;
int dp[2100000];

int main(){
  int n; cin >> n;
  dp[0] = 1;
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=6 && i - j >= 0; j++){
      dp[i] =  add(dp[i], dp[i - j]);
    }
  }
  cout << dp[n] << endl;
  return 0;
}
