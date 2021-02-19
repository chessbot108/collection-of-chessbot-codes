#include <iostream>
#include <vector>
#define ll long long
#define max_v (int)(2e5 +10)
#define add(a, b) ((a%mod) + (b%mod))%mod
const ll mod = (ll)(1e9 +7);
using namespace std;
vector<int> adj[max_v];
ll dp[max_v], vis[max_v];
int n, m;

ll DP(int u){
  if(vis[u]) return dp[u];
  vis[u] = 1;
  for(int v : adj[u]){
    dp[u] = add(dp[u], DP(v));
  }
  return dp[u];
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  while(m--){
    int a, b;
    cin >> a >> b;
    adj[b].push_back(a);
  }
  dp[1] = vis[1] = 1ll;
  cout << DP(n) << '\n';
  return 0;
}
