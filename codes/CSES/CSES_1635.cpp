#include <iostream>
#include <algorithm>
#define add(a, b) ((a%mod + b%mod) %mod)
const int mod = 1e9 +7;
using namespace std;
int c[110], dp[2100000], n, x;
int main(){
  cin >> n >> x;
  for(int i = 0; i<n; i++) cin >> c[i];
  sort(c, c + n);

  dp[0] = 1;
  for(int i = 1; i<=x; i++){
    for(int j = 0; j<n; j++){
      if(i - c[j] < 0) break;
      dp[i] = add(dp[i], dp[i - c[j]]);
    }
  }
  cout << dp[x] << endl;
  return 0;
}
