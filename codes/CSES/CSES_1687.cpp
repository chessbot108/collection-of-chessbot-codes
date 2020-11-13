#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <utility>
#define max_v 220000
#define SQRT 500
#define cont continue
using namespace std;
int par[max_v], super[max_v]; //super stores the "super" parent or the parent SQRT layers up
int n, q; //sqrt decomp for the win
int main(){
  scanf("%d%d", &n, &q);
  for(int i = 2; i<=n; i++){
    scanf("%d", &par[i]);
  }
  
  for(int i = 1; i<=n; i++){
    super[i] = i;
    for(int j = 0; j<SQRT && super[i]; j++) super[i] = par[super[i]];
  }

  while(q--){
    int u, k;
    scanf("%d%d", &u, &k);
    for(; k >= SQRT; k -= SQRT){
      u = super[u];
    }
    while(k--) u = par[u];
    printf("%d\n", u ? u : -1);
  }
  return 0;
}
