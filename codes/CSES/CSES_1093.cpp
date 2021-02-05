#include <iostream>
#define ll long long
#define add(a, b) ((a%mod + b%mod) %mod)
using namespace std;
const ll mod = 1e9+7;
ll dp[260000], n, x;
long long div2(int a){
  long long inv = (mod+1ll)/2ll;
  return (inv * a)%mod;
} 
int main(){
  cin >> n;
  x = (n*(n+1))/4;
  dp[0] = 1ll;
  for(int i = 1; i<=n; i++){
    for(int j = x; j >= i; j--){
      dp[j] = add(dp[j], dp[j - i]);
    }
  }
  
  cout << ((n*(n+1)%4) ? 0 : div2(dp[x])) << endl;
 
  return 0;
}