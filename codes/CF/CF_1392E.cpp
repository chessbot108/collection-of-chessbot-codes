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
#define pow_2(n) (1ll << (n))
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
const int max_v = 100;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

ll ans[max_v][max_v];
int n;

void Q(ll sum){
  int r = 0, c = 0;
  cout << "1 1" << endl;
  for(int i = 0; i<2*(n - 1); i++){
    ll fit = sum&(pow_2((ll)(i + 1)));
    if(r + 1 < n && ans[r + 1][c] == fit) r++;
    else c++;
    cout << r + 1 << " " << c + 1 << endl;
  }
  assert(r == n - 1 && c == n - 1);
  cout.flush();
}


int main(){
	cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      if((i&1) == 1) ans[i][j] = 0ll;
      else ans[i][j] = pow_2(i + j);
    }   
  }
  for(int i = 0; i<n; i++){
    cout << ans[i][0];
    for(int j = 1; j<n; j++){
      cout << " " << ans[i][j];
    }
    cout << endl;
  }
  cout.flush();
  int q; cin >> q;
  while(q--){
    ll sum; cin >> sum;
    Q(sum);
  }
	return 0;
}


