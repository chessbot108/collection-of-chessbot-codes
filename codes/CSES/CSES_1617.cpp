#include <cstdio>
int main(){
  int n, ans = 1, mod = 1e9 + 7; scanf("%d", &n);
  while(n--){
    ans = (ans*2) %mod;
  }
  printf("%d\n", ans);
  return 0;
}
