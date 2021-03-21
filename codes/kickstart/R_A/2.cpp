#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <utility>
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
#define eval(arr1, arr2) (ll)((arr2[i][j] >= 2 && arr1[i][j] >= 2) ? (min(arr1[i][j]/2 -1, arr2[i][j]-1) + min(arr2[i][j]/2 -1, arr1[i][j]-1)) : 0) 
//kids dont do this at home

#define moo printf
#define oom scanf
#define mool puts(""); 
#define loom getline
const ll mod = 1e9 + 7;
const int MX = 1e3 +10, int_max = 0x3f3f3f3f;
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int arr[MX][MX], up[MX][MX], down[MX][MX], ri[MX][MX], le[MX][MX]; //it do be like sometimes


ll solve(){
  int n, m; cin >> n >> m;
  if(n <= 40 && m <= 40){
    for(int i = 0; i<=50; i++){
      for(int j = 0; j<=50; j++){
        arr[i][j] = up[i][j] = down[i][j] = le[i][j] = ri[i][j] = 0;
      }
    }
  }else{
    init(up, 0);
    init(down, 0);
    init(le, 0);
    init(ri, 0);
    init(arr, 0);
  } //lazy me
  ll ans = 0ll; //better safe than sorry
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m; j++){
      cin >> arr[i][j];
    }
  }
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m; j++){
      up[i][j] = (arr[i][j]) ? up[i - 1][j]+1 : 0;
      le[i][j] = (arr[i][j]) ? le[i][j - 1]+1 : 0;
    }
  }
  //moo("wtmoo\n");
  for(int i = n; i; i--){
    for(int j = m; j; j--){
      down[i][j] = (arr[i][j]) ? down[i+1][j]+1 : 0;
      ri[i][j] = (arr[i][j]) ? ri[i][j+1]+1 : 0;
    }
  }
  /** 
  moo("right\n");
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m; j++){
      moo("%3d ", ri[i][j]);
    } mool;
  }
 
  moo("left\n");
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m; j++){
      moo("%3d ", le[i][j]);
    } mool;
  }
  moo("up\n");
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m; j++){
      moo("%3d ", up[i][j]);
    } mool;
  }
  moo("down\n");
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m; j++){
      moo("%3d ", down[i][j]);
    } mool;
  }
  **/
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m; j++){
      ans += eval(up, ri) + eval(up, le) + eval(down, ri) + eval(down, le);
    }
  }
  //moo("%lld\n", ans);
  return ans;
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  for(int i =1; i<=T; i++){
    moo("Case #%d: %lld\n", i, solve());
    //if(i != T) mool;
  }
	return 0;
}


