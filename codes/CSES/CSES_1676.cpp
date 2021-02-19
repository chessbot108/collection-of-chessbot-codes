#include <iostream>
#include <algorithm>
using namespace std;
const int max_v = 2e5 +10;
int par[max_v], sz[max_v];
int n, m, ans = 1;
int find(int u){ if(u != par[u]){ par[u] = find(par[u]); } return par[u];}
void Union(int a, int b){
  a = find(a), b = find(b);
  if(a == b) return ;
  par[a] = b;
  sz[b] += sz[a];
  n--;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 0; i<=n; i++){
    sz[i] = 1, par[i] = i;
  }
  while(m--){
    int a, b;
    cin >> a >> b;
    Union(a, b);
    ans = max(sz[find(a)], ans);
    cout << n << ' ' << ans << '\n';
  }
  return 0;
}
