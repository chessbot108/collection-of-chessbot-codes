#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 110

int v, n;
int wasps[maxn];

bool check(int num){
  int tot = 0;
  for(int i = 0; i < num; i++){
    tot += wasps[i] * num;
  }
  return tot <= v;
}

void bs(){
  int l = 1, r = n+1;
  while(l < r - 1){
    int m = (l + r) >> 1;
    if(check(m)){
      l = m;
    }
    else{
      r = m;
    }
  }

  printf("%d\n", l);
  return;
}

int main(){
  scanf("%d %d", &v, &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &wasps[i]);
  }
  sort(wasps, wasps+n);
  bs();
  return 0;
}
