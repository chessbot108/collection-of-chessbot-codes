#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <utility>
#define max_v 220000 
#define SQRT 500 //n * SQRT is around 1e8. light constant factor lol
#define cont continue
using namespace std;
int par[max_v], super[max_v]; //super stores the "super" parent or the parent SQRT layers up
int n, q; //sqrt decomp for the win
int main(){
  scanf("%d%d", &n, &q); 
  for(int i = 2; i<=n; i++){
    scanf("%d", &par[i]); //this made everything else so much easier.
  }
  
  for(int i = 1; i<=n; i++){
    super[i] = i;
    for(int j = 0; j<SQRT && super[i]; j++) super[i] = par[super[i]]; //sqrt decomp so f*cking op
  } //no edge cases. and all "trivial" looping. better than sparse table. dunno abt euler tour. maybe euler tour can O(1)

  while(q--){
    int u, k;
    scanf("%d%d", &u, &k);
    for(; k >= SQRT; k -= SQRT){
      u = super[u]; //at most SQRT possible super parents to take
    }
    while(k--) u = par[u]; //also at most SQRT possible nodes to iterate manually
    printf("%d\n", u ? u : -1); //AC frist try lol
  }
  return 0;
}
