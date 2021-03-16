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
#include <map>

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

ll x; int n;
vector<pair<ll, int>> arr;
//quadratic two pointers method
void solve(){
  for(int i = 0; i<n - 2; i++){
    int j = n - 1, k = i + 1;
    ll s = x - arr[i].first;
    while(k < j){
      ll t = arr[j].first + arr[k].first;
      if(t < s){
        k++;
      }else if(t > s){
        j--;
      }else{
        moo("%d %d %d\n", arr[i].second, arr[j].second, arr[k].second);
        return ;
      }
    }
  }

  moo("IMPOSSIBLE\n");
}

int main(){
  oom("%d%lld", &n, &x);
  for(int i = 0; i<n; i++){
    ll a; oom("%lld", &a);
    arr.pb(mp(a, i + 1));
  }
  
  sort(arr.begin(), arr.end());
  solve();
  return 0;
}
