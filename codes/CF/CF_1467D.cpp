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
const int max_v = 5e3 +10;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

ll dp[max_v][max_v], arr[max_v], contr[max_v];
ll n, k, q, ans = 0ll;

int main(){
	cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> k >> q;
  for(int i = 1; i<=n; i++){
    cin >> arr[i];
    dp[i][0] = 1ll;
  }
  
  for(int j = 1; j<=k; j++){
    for(int i = 1; i<=n; i++){
      dp[i][j] = add(dp[i - 1][j - 1], dp[i + 1][j - 1]);
    }
  }

  for(int i = 1; i<=n; i++){
    for(int j = 0; j<=k; j++){
      contr[i] = add(contr[i], mul(dp[i][j], dp[i][k - j]));
    }
    //cout << i << " " << contr[i] << endl;
    ans = add(ans, mul(contr[i], arr[i]));
  }

  while(q--){
    ll i, val;
    cin >> i >> val;
    ans = add(ans, mul(contr[i], mod + (val - arr[i])));
    arr[i] = val;
    cout << ans << '\n';
  }
  
	return 0;
}


