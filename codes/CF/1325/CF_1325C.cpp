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

vector<pii> adj[MX];
int ans[MX], cnt = 0, n;
int main(){
	cin.tie(0) -> sync_with_stdio(0);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin >> n;
  for(int i = 1; i<n; i++){
    int a, b;
    cin >> a >> b;
    adj[a].pb(mp(b, i));
    adj[b].pb(mp(a, i));
  }

  for(int i = 1; i<=n; i++){
    if(adj[i].size() >= 3){
      for(int j = 0; j<3; j++){
        //cout << i << " " << adj[i][j].first << " " << adj[i][j].second << endl;
        ans[adj[i][j].second] = ++cnt;
      }
      break;
    }
  }

  for(int i = 1; i<n; i++){
    if(ans[i]) cout << ans[i] - 1 << '\n';
    else cout << cnt++ << '\n';
  }   
  

 	return 0;
}


