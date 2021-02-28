#include <iostream>
#include <vector>
#define pb push_back
const int max_v = 2e5 +10;
using namespace std;
vector<int> adj[max_v];
int dist[max_v], n;
bool ckmax(int& a, int b){
  if(b > a){
    a = b;
    return true;
  }
  return false;
} 
void dfs(int u, int p, int d){
  ckmax(dist[u], d);
  for(int v : adj[u]){
    if(v != p)
      dfs(v, u, d + 1);
  }
}

int far(){
  int ans, maxi = 0;
  for(int i = 1; i<=n; i++){
    if(ckmax(maxi, dist[i])) ans = i;
  }
  return ans;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i<n; i++){
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  dfs(1, 0, 0);
  dfs(far(), 0, 0);
  dfs(far(), 0, 0);
  for(int i = 1; i<=n; i++){
    cout << dist[i] << '\n';
  }
  return 0;
}

