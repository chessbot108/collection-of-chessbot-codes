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
#include <iomanip>
#define cont continue
#define pow2(n) (1 << (n))
#define ll long long
#define pii pair<ll, ll>
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


vector<pii> miners, diamonds;

int main(){
	cin.tie(0) -> sync_with_stdio(0);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t; cin >> t;
  cout << fixed << setprecision(15);
  while(t--){
    int n; cin >> n;
    miners.clear(); diamonds.clear();
    for(int i = 0; i<n*2; i++){
      ll a, b; cin >> a >> b;
      if(!a) miners.pb(mp(0, (ll)abs(b)));
      else diamonds.pb(mp((ll)abs(a), 0));
    }
    sort(miners.begin(), miners.end());
    sort(diamonds.begin(), diamonds.end());
    long double ans = 0.0;
    for(int i = 0; i<n; i++){
      ans += sqrt((long double)(miners[i].second*miners[i].second + diamonds[i].first*diamonds[i].first));
    }
    cout << ans << '\n';
  }
	return 0;
}


