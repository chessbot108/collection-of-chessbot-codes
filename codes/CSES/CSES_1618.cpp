#include <cstdio>
int main(){
  int n, ans = 0, i = 5; scanf("%d", &n);
  while(i <= n) ans += n/i, i *= 5;
  printf("%d\n", ans);
  return 0;
}
