#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[220000];
int n, ans, a;

void dfs(int u, int p, int d){
  if(d > ans) ans = d, a = u;
  for(int v : adj[u])
    if(v != p)  
      dfs(v, u, d + 1);

}


int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n;
  for(int i = 1; i<n; i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 0, 0);
  dfs(a, 0, 0);
  cout << ans << "\n";
  return 0;
}

