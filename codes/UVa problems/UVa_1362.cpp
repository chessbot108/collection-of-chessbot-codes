#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

const int mod = 1000000000;
const int max_v = 305;

long long dp[max_v][max_v];
char str[max_v];

int main(){
  
  while(scanf("%s", str) == 1){
      memset(dp, 0, sizeof(dp));
      int n = (int)strlen(str);
      for(int i = 0; i<n; i+=2){
        for(int j = 0; i+j<n; j++){
           int l = j, r = i + j;
           if(l == r) dp[l][r] = 1;
           if(str[l] == str[r])
            for(int k = l + 2; k<=r; k += 2)
              if(str[l] == str[k] && str[r] == str[k])
                dp[l][r] = (dp[l][r] + dp[l + 1][k - 1] * dp[k][r]) % mod;       
        }

      }

      printf("%lld\n", dp[0][n-1]%mod);
  }




  return 0;
}
