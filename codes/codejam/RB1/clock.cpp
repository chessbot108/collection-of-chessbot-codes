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
#include <queue>
#include <set>

#define cont continue
#define pow2(n) (1 << (n))
#define ll long long
#define lb long double
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ins insert

#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define tern(a, b, c) ((a) ? (b) : (c))

#define pbenq priority_queue
#define moo printf
#define oom scanf
#define mool puts("") 
#define loom getline
#define orz assert

const ll mod = 1e9 + 7;
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
  freopen((file_name+".in").c_str(), "r", stdin);
  freopen((file_name+".out").c_str(), "w+", stdout);
}

//scuffed statement 2.0
//append sort but worse
lb arr[5];

lb dmod(lb val, ll w){
  lb temp, temp2;
  temp2 = modf(val, &temp);
  //moo("%.3LF %.10LF, %.10LF, %lld, %.10LF\n", val, temp, temp2, w, (lb)((ll)temp%w));
  return (lb)((floor((ll)temp %w)) + temp2);
} 
const lb eps = 1e-9;
bool cmp(lb a, lb b){
  return fabs(a - b) < eps;
}

void solve(){
  lb a, b, c, s = -1.0; cin >> a >> b >> c;
  a = a/(12ll * 1e10);
  b = b/(12ll * 1e10);
  c = c/(12ll * 1e10);
  //moo("%.3LF %.3LF %.3LF\n", a, b, c);
  arr[0] = a, arr[1] = b, arr[2] = c;
  sort(arr, arr + 3);
  do{
    for(lb x = 1.0 - dmod(arr[0], 1.0); x <=720.0; x = x + 1.0){
      //if(arr[1] != (ll)arr[1] || arr[2] != (ll)arr[2]) cont;
      //if(x != 0) break;
      //moo("%.3LF %.3LF %.3LF.... %.3LF %.3LF, %.3LF %.3LF\n", dmod(arr[0] + x, 360), arr[1] + x, arr[2] + x, dmod(arr[1] + x, 6), dmod(arr[1] + x, 6) * 60.0, dmod(arr[2] + x, 15), dmod(arr[2] + x, 15)  * 12.0);
      lb t = dmod(arr[1], 6ll) * 60.0;
      //moo("WTMOO %.12LF %d\n", t, (int)(t == (lb)18.0));
      if(cmp((lb)dmod(arr[1] + x, 6) * 60.0, (lb)dmod(arr[0] + x, 360)) && cmp((lb)(dmod(arr[2] + x, 30)* 12.0), (lb)dmod((arr[1] + x), 360))){
        s = x; break;
      }
    }
    if(s >= 0) break;
  }while(next_permutation(arr, arr + 3));
  moo("%d %d %d 0\n", (int)(dmod(arr[2] + s, 360)/30), (int)(dmod(arr[1] + s, 360)/6), (int)(dmod(arr[0] + s, 360)/6));

}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  for(int i = 1; i<=T; i++){
    moo("Case #%d: ", i); solve();
  }
  return 0;
}


