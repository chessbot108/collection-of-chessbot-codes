#include <cstdio>
#include <cstring>
char str[1100000];
int freq[130];
int main(){
  scanf("%s", str);
  int n = strlen(str), odd = 0;
  for(int i = 0; i<n; i++) freq[str[i]]++;
  for(int i = 0; i<129; i++) odd += freq[i]%2;
  if(odd <= 1) puts("YES");
  else puts("NO");
  return 0;
}
