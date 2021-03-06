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
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int par[MX], sz[MX], n, q;
vector<pair<int, pii>> edge;
ll ans[MX];


int find(int u){
  if(u != par[u]) par[u] = find(par[u]);
  return par[u];
}

int get(int u){
  return sz[find(u)];
}

void Union(int a, int b){
  a = find(a), b = find(b);
  if(a == b) return ;
  if(sz[a] > sz[b]) swap(a, b);
  par[a] = b;
  sz[b] += sz[a];
}

void mkdsu(){
  for(int i = 0; i<=n; i++){
    par[i] = i;
    sz[i] = 1;
  }
}

void solve(){
  sort(edge.begin(), edge.end());
  mkdsu();
  for(const auto& e : edge){
    //cout << e.first.first << " " << e.first.second << "  " << e.second << " " << ans[e.second] << endl;
    ans[e.first] += (ll)get(e.second.first) * (ll)get(e.second.second);
    Union(e.second.first, e.second.second);
  }
  for(int i = 1; i<=2e5; i++){
    ans[i] += ans[i - 1];
  }
}



int main(){
	cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> q;
  edge.resize(n - 1);
  for(int i = 0; i<n - 1; i++){
    int a, b, c;
    cin >> a >> b >> c;
    edge[i] = mp(c, mp(a, b));
  }
  solve();
  while(q--){
    int w; cin >> w;
    cout << ans[w] << ' ';
  }
  cout << '\n';
	return 0;
}


