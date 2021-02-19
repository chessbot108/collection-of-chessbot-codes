#include <cstdio>
#define add(a, b) ((a%mod + b%mod) %mod)
using namespace std;
const int mod = 1e9 +7;
int dp[1100][1100], n;
char str[1100][1100];
int main(){
  scanf("%d", &n);
  for(int i = 0; i<n; i++) scanf("%s", str[i]);
  dp[0][1] = 1;
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n; j++){
      if(str[i-1][j-1] == '*') continue;
      dp[i][j] = add(dp[i][j - 1], dp[i - 1][j]);
    }
  }
  printf("%d\n", dp[n][n]);
  return 0;
}
