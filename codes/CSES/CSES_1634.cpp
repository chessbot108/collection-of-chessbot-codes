#include <iostream>
#include <cstring>
#include <algorithm>
#define int_max 0x3f3f3f3f
#define cont continue
using namespace std;
int dp[2100000], c[110], n, x;
int main(){
  cin >> n >> x;
  for(int i = 0; i<n; i++) cin >> c[i];

  memset(dp, 0x3f, sizeof(dp));

  dp[0] = 0;
  sort(c, c + n);
  for(int i = 1; i<=x; i++){
    for(int j = 0; j<n; j++){
      if(i - c[j] < 0) break;
      dp[i] = min(dp[i], dp[i - c[j]] + 1);
    }
  }
  cout << ((dp[x] == int_max) ? -1 : dp[x]) << endl;

  return 0;
}
