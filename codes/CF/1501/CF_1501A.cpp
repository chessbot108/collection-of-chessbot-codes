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
//geniousity limit exceeded
#define moo printf
#define oom scanf
const ll mod = 1e9 + 7;
const int MX = 1e5 +10, int_max = 0x3f3f3f3f;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int a[MX], b[MX], t[MX];
int n;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  int T; cin >> T;
  while(T--){
    cin >> n;
    for(int i = 1; i<=n; i++){
      cin >> a[i] >> b[i];
    }
    for(int i = 1; i<=n; i++){
      cin >> t[i];
    }
    ll ti = 0ll; //si this needed?
    for(int i = 1; i<=n; i++){
      //moo("ti: %d\n", ti);
      ti = max((ll)a[i], ti + (a[i] - b[i - 1])) + t[i];
      //moo("ti: %d, %d %d\n", ti, (a[i] - b[i - 1]), t[i]);
      if(i == n) break;
      ti += (b[i] - a[i] +1ll)/2ll;
      //moo("ti: %d, %d\n", ti, (b[i] - a[i] +1ll)/2ll);
      ti = max(ti, (ll)b[i]);
      //moo("ti: %d, b[i]: %d\n", ti, b[i]);
    }
    cout << ti << "\n";
  }
	return 0;
}


