#include <cstdio>
#include <cstring>
int max(int a, int b){ return (a > b) ? a : b; }
char str[1100000];
int main(){
  int n, ans = 0, cur = 1;
  scanf("%s", str); n = strlen(str);
  for(int i = 1; i<=n; i++){
    if(str[i] == str[i - 1]) cur++;
    else ans = max(ans, cur), cur = 1;
  }
  printf("%d\n", ans);
  return 0;
}
