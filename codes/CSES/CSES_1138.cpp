#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>

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
const int max_v = 4e5 +10, int_max = 0x3f3f3f3f;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}


ll BIT[max_v * 2], arr[max_v];
int trav[max_v * 2], st[max_v], en[max_v];
int n, q, ind;
vector<int> adj[max_v];

ll S(int k){ return (!k) ? 0ll : (BIT[k] + S(k - lsb(k))); }
void U(int k, ll val){ for(; k<=n*2; k += lsb(k)) BIT[k] += val; }


void dfs(int u, int p){
  trav[++ind] = u;
  st[u] = ind;
  for(int v : adj[u])
    if(v != p)
      dfs(v, u);
  trav[++ind] = u;
  en[u] = ind;
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> q;
  for(int i = 1; i<=n; i++){
    cin >> arr[i];
  }

  for(int i = 1; i<n; i++){
    int a, b; cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  
  dfs(1, 0);
 
  for(int i = 1; i<=n; i++){
    U(st[i], arr[i]);
    U(en[i], -1ll * arr[i]);
  } 
  
  while(q--){
    int op; cin >> op;
    if(op == 1){
      int a; ll b;
      cin >> a >> b;
      b -= arr[a];
      U(st[a], b);
      U(en[a], -1ll * b);
      arr[a] += b;
    }else{
      int a; cin >> a;
      cout << S(st[a]) << '\n';
    }
  }
	return 0;
}


