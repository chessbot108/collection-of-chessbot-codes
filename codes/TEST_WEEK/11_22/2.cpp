//XJOI 1634 2
//test 11 problem 2
//cows at large gold


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <list>
#include <queue>
#include <stack>
//#include <unordered_map>
//#include <unordered_set>
#include <functional>

#define max_v 1000000
#define int_max 0x3f3f3f3f
#define cont continue
#define pow_2(n) (1 << (n))
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define LOG2(n) ((int)(ceil(log2((n)))))
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

const int SQRT = 600;

int sum[max_v], dep[max_v], par[max_v], pre[max_v], l[max_v], r[max_v], add[max_v], leaf[max_v], super[max_v]; //sum and add for seg tree, pre, l, r for tree magic
list<int> adj[max_v]; 
int ind = 0, s = 0, leaf_ind = 0;
int n, K;

void U(int qL, int qR, int k, int val, int L, int R){
  //printf("%d %d %d %d %d %d\n", qL, qR, k, val, L, R);
  if(qR <= L || R <= qL || R <= L) return ;
  if(qL <= L && R <= qR){
    add[k] += val;
    return ;
  }
  int mid = (L + R) / 2;
  U(qL, qR, LC(k), val, L, mid);
  U(qL, qR, RC(k), val, mid, R);
  sum[k] = add[LC(k)] * (mid - L) + sum[LC(k)] + add[RC(k)] * (R - mid) + sum[RC(k)];
}

int S(int qL, int qR, int k, int L, int R){
  if(qR <= L || R <= qL || R <= L) return 0;
  if(qL <= L && R <= qR) return sum[k] + (R - L) * add[k];
  int mid = (L + R) / 2;
  return (min(R, qR) - max(L, qL)) * add[k] + S(qL, qR, LC(k), L, mid) + S(qL, qR, RC(k), mid, R);
}

int S(int p){
  return S(p, p + 1, 0, 0, s);
}

void dfs(int u, int p, int d){
  if(adj[u].size() == 1){ //the parent is the only "child"
    leaf[leaf_ind++] = u;
  }
  par[u] = p;
  l[u] = ind;
  pre[ind++] = u;
  dep[u] = d;

  for(int v : adj[u]){
    if(p == v) cont;
    dfs(v, u, d + 1);
  }

  r[u] = ind;
  pre[ind++] = u;
}



int PAR(int u, int k){
  //parent of u k layers up
  for(; k >= SQRT; k -= SQRT) u = super[u];
  for(; k; k--) u = par[u];
  return u;
}

void precomp(){
  for(int i = 1; i<n*2; i++){
    for(int j = 0; super[i] && j < SQRT; j++) super[i] = par[super[i]];
  }
}

void add_edge(int a, int b){
  adj[a].push_back(b);
  adj[b].push_back(a);
}

bool cmp(int a, int b){
  return dep[a] < dep[b];
}

int main(){
  //setIO("atlarge");
  scanf("%d%d", &n, &K);
  s = pow_2(LOG2(n*2))*2; 
  for(int i = 1; i<n; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    add_edge(a, n + i); //n + i is fake node
    add_edge(b, n + i); //to make the case where the tunnels are odd
  }
  dfs(K, 0, 0);
  precomp();
  sort(leaf, leaf + leaf_ind, cmp);
  //for(int i = 0; i<ind; i++) printf("%d ", pre[i]); puts("");
  int ans = 0;
  for(int i = 0; i<leaf_ind; i++){
    int u = leaf[i], d = dep[leaf[i]];
    if(u == K || S(l[u])) cont;
    ans++;
    int p = PAR(u, d/2);
    //assert(PAR(p, d/2) == K);
    U(l[p], r[p], 0, 1, 0, s);
    //printf("---------\nu: %d\nd: %d\npar: %d\nl[u]: %d\nr[u]: %d\n\n", u, dep[u], p, l[p], r[p]);
    //for(int i = 0; i<ind; i++) printf("%2d ", pre[i]); puts("");
    //for(int i = 0; i<ind; i++) printf("%2d ", S(i)); puts("");
  }
  printf("%d\n", ans);

	return 0;
}

