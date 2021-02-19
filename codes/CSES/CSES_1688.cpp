#include <iostream>
#include <vector>
#include <algorithm>
#define max_v 220000
#define cont continue
#define lsb(x) ((x)&-(x))
using namespace std;

const int base = 3, xp = 10;
int super[max_v][xp], dep[max_v], p[xp];
int n, m;
vector<int> adj[max_v];

void dfs(int u, int p, int d){
  super[u][0] = p;
  dep[u] = d;
  for(int v : adj[u])
    if(v != p)
      dfs(v, u, d + 1);
}

void precomp(){
  p[0] = 1;
  for(int i = 1; i<=xp; i++){
    p[i] = p[i - 1] * base;
    for(int j = 1; j<=n; j++){
      super[i][j] = i;
      for(int k = 0; k<base && super[i][j]; k++){
        super[i][j] = super[super[i][j - 1]][j - 1];
      }
    }
  }
}

int k_up(int u, int k){
  for(int i = xp; i >= 0; i--){
    while(k >= p[i]) k -= p[i], u = super[u][i];
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
    int a;
    cin >> a;
    adj[a].push_back(i);
    adj[i].push_back(a);
  }
  adj[0].push_back(1);
  dfs(1, 0, 1);  
  precomp();
  while(m--){
    int a, b;
    cout << LCA(a, b) << '\n';
  }

  return 0;
}

