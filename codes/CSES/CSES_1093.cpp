#include <iostream>
#define add(a, b) ((a%mod + b%mod) %mod)
using namespace std;
const int mod = 1e9+7;
int dp[1100], n, x;
long long div2(int a){
  long long inv = (long long)(mod+1)/2;
  return (inv * a)%mod;
} 
int main(){
  cin >> n;
  x = (n*(n+1))/4;
  dp[0] = 1;
  for(int i = 1; i<=n; i++){
    for(int j = x; j >= i; j--){
      dp[j] = add(dp[j], dp[j - i]);
    }
  }
  
  cout << ((n*(n+1)%4) ? 0 : div2(dp[x])) << endl;

  return 0;
}
