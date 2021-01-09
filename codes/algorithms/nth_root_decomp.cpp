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

#define max_v 210000
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

const int RT = 2, LOG = 18; //RT^LOG approx max_v
list<int> adj[max_v];
int super[max_v][LOG * 2], par[max_v], dep[max_v], sub[max_v], base[max_v], n, q; 

int dfs(int u, int p, int d){ //general util dfs
  par[u] = super[u][0] = p;
  dep[u] = d;
  sub[u] = 1;
  //printf("%d: %d %d\n", u, super[u][0], d + 1);
  for(int v : adj[u])
    if(v != p)
        sub[u] += dfs(v, u, d + 1);
  return sub[u];
}

void precomp(){
  base[0] = 1;
  for(int k = 1; k<=LOG; k++){
    base[k] = base[k - 1] * RT;
    for(int i = 1, j; i<=n; i++){
      for(j = 0, super[i][k] = i; j < RT && super[i][k]; j++){
        super[i][k] = super[super[i][k]][k - 1];
        //printf("%d %d %d\n", k, i, j);
      }
    }
  }
}

int k_up(int u, int k){
  for(int i = LOG; i >= 0; i--){
    //printf("%d %d; %d\n", u, k, i);
    while(k >= base[i]){k -= base[i], u = super[u][i]; /**printf("%d %d; %d\n", u, k, i); **/}
  }
  return u;
}

int LCA(int u, int v){
  if(dep[u] < dep[v]) swap(u, v);
  //printf("q: lca(%d %d)\nu moves up %d becoming %d\n", u, v, dep[u] - dep[v], k_up(u, dep[u] - dep[v]));
  u = k_up(u, dep[u] - dep[v]);
  //printf("%d\n", u);
  if(u == v) return u;
  for(int i = LOG; i >= 0; i--){
    while(super[u][i] != super[v][i]) u = super[u][i], v = super[v][i];
  }
  return (par[u]) ? par[u] : u; //cant return 0
}

int main(){
  scanf("%d%d", &n, &q);
  for(int i = 1; i<n; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 0, 0);
  precomp();
  /** 
  for(int i = 0; i<=LOG; i++){
    printf("for k = %d: ", i);
    for(int j = 1; j<=n; j++) printf("%3d", super[j][i]); puts("");
  }
  **/
  
  while(q--){
    int a, b;
    scanf("%d%d", &a, &b);
    int l = LCA(a, b);
    //printf("\tLCA(%d, %d) == %d\n\tdep:\n\t\ta -> %d\n\t\tb -> %d\n\t\tl -> %d\n", a, b, l, dep[a], dep[b], dep[l]);
    printf("%d\n", (dep[a] - dep[l]) + (dep[b] - dep[l]));
  }
	return 0;
}

