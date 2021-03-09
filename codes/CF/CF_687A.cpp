#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>

#define cont continue
#define pow2(n) (1 << (n))
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
const int MX = 1e5 +10, int_max = 0x3f3f3f3f;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

vector<int> adj[MX];
int col[MX], n, m, R, B;


bool dfs(int u, int c){
  //cout << u << " " << c << endl;
  if(col[u] != 0) return (col[u] == c);
  col[u] = c;
  if(c == 1) R++;
  else B++;
  bool ans = 1;
  for(int v : adj[u]){
    //cout << "\t"; cout.flush();
    ans &= dfs(v, 3 - c);
  }
  return ans;
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin >> n >> m;
  for(int i = 0; i<m; i++){
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  bool ans = 1;
  for(int i = 1; i<=n; i++){
    if(col[i] == 0) ans &= dfs(i, 1);
  }
  if(ans){
    cout << R << '\n';
    for(int i = 1; i<=n; i++){
      if(col[i] == 1) cout << i << " ";
    }
    cout << '\n' <<  B << '\n'; 
    for(int i = 1; i<=n; i++){
      if(col[i] == 2) cout << i << " ";
    }
    cout << '\n';
  }else{
    cout << "-1\n";
  }
	return 0;
}


