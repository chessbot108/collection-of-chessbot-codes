#include <iostream>
using namespace std;
int par[110000], sz[110000], n, m, cc;
int find(int x){
  if(par[x] != x) par[x] = find(par[x]);
  return par[x];
}
void Union(int u, int v){
  v = find(v), u = find(u);
  if(u == v) return ;
  if(sz[u] < sz[v]) swap(u, v);
  par[v] = u, sz[u] = sz[u] + sz[v];
}

int main(){
  cin.tie(NULL) -> sync_with_stdio(0);
  cin >> n >> m;
  cc = n;
  for(int i = 0; i<=n; i++){
    par[i] = i, sz[i] = 1;
  }
  
  while(m-- && cc > 1){
    int a, b; cin >> a >> b;
    if(find(a) != find(b)) cc--;
    Union(a, b);
  }
  cout << cc - 1 << '\n';
  for(int i = 1; i<=n; i++){
    if(find(i) != find(1))
      cout << find(i) << ' ' << find(1) << '\n';
    Union(i, 1);
  }
  return 0;
}

