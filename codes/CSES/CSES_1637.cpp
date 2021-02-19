#include <cstdio>
#define max_v 1100000
#define cont continue

int dp[max_v];
int min(int a, int b){ return (a < b) ? a : b; }

int f(int a){
  
  if(dp[a]) return dp[a];
  if(!a) return 0;
  dp[a] = max_v;

  for(int i = a; i; i /= 10){
    dp[a] = min(dp[a], 1 + f(a - i%10));  
  }
  

  return dp[a];
}

int main(){
  int n;
  scanf("%d", &n);
  printf("%d\n", f(n));
  return 0;
}
