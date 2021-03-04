#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>

#define int_max 0x3f3f3f3f
#define cont continue
#define pow_2(n) (1 << (n))
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))

const ll mod = 1e9 + 7;
const int max_v = 600;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

vector<pii> adj[max_v];
vector<int> edges;
int vis[max_v], st[max_v]; //vis and in stack
int n, m;
bool dfs(int u, int op){
  //cout << "\t" << u << '\n';
  
  st[u] = vis[u] = 1;
  for(auto e : adj[u]){
    if(e.second == op) cont;
    if(!op) edges.pb(e.second);
    //cout << "\t\t" << e.first << " " << (int)st[e.first] << "\n";
    if((st[e.first]) || (!vis[e.first] && !dfs(e.first, op))) return false;
    if(!op) edges.pop_back();
  }
  st[u] = 0;
  return true;
}


int main(){
	cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 0; i<m; i++){
    int a, b;
    cin >> a >> b;
    adj[a].pb(mp(b, i + 1));
    //adj[b].pb(mp(a, RC(i)));
    
  }
  bool ans = 1;  
  for(int i = 1; i<=n; i++){
    if(!dfs(i, 0)){
      ans = 0;
      break;
    }
  }   

  for(int del : edges){
    init(vis, 0);
    init(st, 0);
    //cout << "status: " <<  del << ' ' << (int)ans << '\n';
    bool cur = 1;
    for(int i = 1; i<=n; i++){
      //cout << del << " " << i << '\n';
      if(!vis[i]) cur &= dfs(i, del);
    }
    ans |= cur;
  }
  if(ans) cout << "YES\n";
  else cout << "NO\n";
	return 0;
}


