#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

#define max_v 1100000
#define LOGN 50
#define cont continue
#define pow_2(n) (1 << (n))
#define LOG2(n) ((int)(ceil(log2((n)))))
using namespace std;

char str[max_v];
int sa[max_v], rk[max_v], buckets[max_v], lcp[max_v]; //using buckets for readability
int tmp[max_v], pos[max_v], st[max_v * 2][LOGN], n;

void print_arr(int n, int * arr){
  for(int i = 1; i<=n; i++) printf("%d ", arr[i]);
  puts("");
}

void comp_SA(){
  int mx = 260;
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



void make_lcp(){
  for(int i = 1; i<=n; i++){
    lcp[rk[i]] = max(0, lcp[rk[i - 1]] - 1);
    for(; str[i + lcp[rk[i]]] == str[sa[rk[i] - 1] + lcp[rk[i]]]; lcp[rk[i]]++); //clean and concise from teachers code
  }//linear complexity. proving this was a massive pain
}

void rmq_precomp(){
  memset(st, 0x3f, sizeof(st));
  for(int i = 1; i<=n; i++) st[i][0] = lcp[i];
  for(int j = 1; pow_2(j) <= n; j++){
    for(int i = 1; i <= n; i++){
      st[i][j] = min(st[i][j - 1], st[i + pow_2(j - 1)][j - 1]);
    } 
  }
}
int query(int a, int b){ //max prefix amoung suffix starting at a and suffix starting at b [a, b]
  //printf("%d -> %d\n%d -> %d\n", a, rk[a] + 1, b, rk[b] + 1);
  a = rk[a] + 1, b = rk[b] + 1;
  if(a > b) swap(a, b);
  int k = log2(b - a);
  
  assert(b - pow_2(k) >= 1);
  return min(st[a][k], st[b - pow_2(k)][k]);
}


int main(){
  scanf("%s", str + 1);
  n = strlen(str + 1);
  comp_SA();
  make_lcp();
  printf("i   rk  sa  lcp\n");
  for(int i = 1; i<=n; i++) printf("%d   %d   %d   %d\n", sa[i], rk[sa[i]], sa[sa[i]], lcp[rk[sa[i]]]);
  int q;
  
  for(int i = 1; i<=n; i++){
    printf("%d ", i);
    for(int j = i; j<=n; j++) printf("%c", str[j]);
    puts("");
  }
  //assert(false);
  rmq_precomp();
  scanf("%d", &q);
  while(q--){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", query(a, b));
  }
	return 0;
}

