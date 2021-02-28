#include <iostream>
#include <vector>
#include <algorithm>
#define max_v 220000
#define cont continue
#define lsb(x) ((x)&-(x))
#define pow_2(x) (1 << (x))
using namespace std;
 
int super[max_v][20], dep[max_v];
int n, m;
vector<int> adj[max_v];
 
int dfs(int u){
  if(u == 1) return dep[u] = 1;
  else if(dep[u]) return dep[u];
  else return dep[u] = 1 + dfs(super[u][0]);
}
 
void precomp(){
  for(int j = 1; pow_2(j) <= n; j++){
    for(int i = 1; i<=n; i++){
      super[i][j] = super[super[i][j - 1]][j - 1];
    }
  }
}
 
int k_up(int u, int k){
  for(int i = xp; i >= 0; i--){
    while(k >= pow_2(i)) k -= pow_2(i), u = super[u][i];
  }
  return u;
}
 
int LCA(int a, int b){
  if(dep[b] < dep[a]) swap(a, b);
  b = k_up(b, dep[b] - dep[a]);
  if(a == b) return a;
  for(int i = xp; i >= 0; i--){
    while(super[a][i] != super[b][i]) a = super[a][i], b = super[b][i];
  }
  return (super[a][0]) ? super[a][0] : a;
}
 
int main(){
  cin.tie(0); ios::sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 2; i<=n; i++){
    cin >> super[i][0];
  }
  for(int i = 1; i<=n; i++){
    dfs(i);
  }
  
  precomp();
  while(m--){
    int a, b;
    cin >> a >> b;
    cout << LCA(a, b) << '\n';
  }
 
  return 0;
}
