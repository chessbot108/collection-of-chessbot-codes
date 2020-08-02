#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

#define max_v 1100000
#define cont continue
#define pow_2(n) (1 << (n))

using namespace std;

char str[max_v];
int sa[max_v], rk[max_v], buckets[max_v], lcp[max_v]; //using buckets for readability
int tmp[max_v], pos[max_v];

void print_arr(int n, int * arr){
  for(int i = 1; i<=n; i++) printf("%d ", arr[i]);
  puts("");
}

void comp_SA(){
  int n = strlen(str + 1), mx = 260;
  for(int i = 1; i<=n; i++){
    sa[i] = i;
    rk[i] = str[i];
  }

  for(int i = 1; i >> 1 < n; i <<= 1){
    int k = i >> 1, p = k;
    for(int j = 1; j<=k; j++) buckets[j] = n - (j - 1);
    for(int j = 1; j<=n; j++) if(sa[j] > k) buckets[++p] = sa[j] - k;
    memset(pos, 0, sizeof(pos));
    for(int j = 1; j<=n; j++) pos[rk[j]]++;
    for(int j = 1; j<=mx; j++) pos[j] += pos[j - 1];
    for(int j = n; j; j--) sa[pos[rk[buckets[j]]]--] = buckets[j];
    for(int j = 1; j<=n; j++) tmp[sa[j]] = tmp[sa[j - 1]] + (rk[sa[j]] != rk[sa[j - 1]] || rk[sa[j] + k] != rk[sa[j - 1] + k]);
    for(int j = 1; j<=n; j++) rk[j] = tmp[j];
    mx = rk[sa[n]];
    if(mx == n) break; //optimization to help run faster on 'sparser strings'
  }
  //this passed luogu sample problem. so it's all good
}







int main(){
  scanf("%s", str + 1);
  int n = strlen(str + 1);
  comp_SA();
  for(int i = 1; i<=n; i++) printf("%d ", sa[i]);
	return 0;
}

