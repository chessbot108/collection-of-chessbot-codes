#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>

#define max_v 110000
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
#define add(a, b) ((a%mod + b%mod)%mod)
#define mul(a, b) ((a%mod * b%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))

const ll mod = 1e9 + 7;

using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int col[max_v], vis[max_v], sub[max_v], n;
vector<int> adj[max_v];

int getsz(int u, int p){
  if(vis[u]) return 0;
  sub[u] = 0;
  for(int v : adj[u]){
    if(v != p && !vis[v]){
      sub[u] += getsz(v, u);
    }
  }
  return ++sub[u];
}

int centr(int u, int p, int sz){
  for(int v : adj[u]){
    if(!vis[v] && v != p && sub[v] > sz/2){
      return centr(v, u, sz);
    }
  }
  return u;
}

void mktree(int u, int c){
  int C = centr(u, 0, getsz(u, 0));
  vis[C] = 1;
  col[C] = c++;
  for(int v : adj[C]){
    if(!vis[v]){
      mktree(v, c);
    }
  }
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
  mktree(1, 0);
  for(int i = 1; i<=n; i++){
    cout << (char)('A' + col[i]) << ' ';
  }
  cout << '\n';
	return 0;
}


