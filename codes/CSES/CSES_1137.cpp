#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#define max_v 410000
#define cont continue
using namespace std;
int l[max_v], r[max_v], ord[max_v];
long long BIT[max_v], arr[max_v];
 
 
vector<int> adj[max_v];
int n, q, cnt = 0;

//2 line BIT with recursive sum and iterative update. my greatest pride
void U(int k, long long val){ for(; k <=max_v - 1; k += k&-k) BIT[k] += val; }
long long S(int k){ return (!k) ? 0ll : BIT[k] + S(k - (k&-k)); } //i can't compile code at school so i spent 10 minutes debugging to find my query was wrong
 
void dfs(int u, int p){
  l[u] = ++cnt; //might be useless, better safe than sorry.
  ord[cnt] = u; 
  
  for(int v : adj[u]){
    if(v == p) cont;
    dfs(v, u);
  }
  r[u] = ++cnt;
  ord[cnt] = u;
  U(cnt, arr[u]); //to make query/update easier. PIE makes it so that update at start or end both work
}
 
 
 
 
int main(){
  scanf("%d%d", &n, &q);
  for(int i = 1; i<=n; i++){
    scanf("%lld", &arr[i]);
  }
 
  for(int i = 1; i<n; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 0);
  while(q--){
    int op;
    scanf("%d", &op);
    if(op - 1){
      int u;
      scanf("%d", &u);
      printf("%lld\n", S(r[u]) - S(l[u]));
    }else{
      int u; long long k;
      scanf("%d%lld", &u, &k);
      U(r[u], k - arr[u]);
      arr[u] = k;
    }
  }
  return 0;
}
 









































