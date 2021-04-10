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
#define cont continue

#define pow2(n) (1 << (n))
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ins insert
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define tern(a, b, c) ((a) ? (b) : (c))
//the following ones give off usaco vibes
#define pbenq priority_queue
#define moo printf
#define oom scanf
#define mool puts("") 
#define loom getline

const ll mod = 1e9 + 7;
const int MX = 1e2 +10, int_max = 0x3f3f3f3f;
//aHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

ll arr[MX];

int dig(ll x){
  return tern(!x, 0, dig(x/10ll) +1);
}

int solve(){
  int n; cin >> n;
  init(arr, 0);
  for(int i = 0; i<n; i++){
    cin >> arr[i];
  }
  //moo("%d\n", dig(1000));
  int ans = 0;
  for(int i = 1; i<n; i++){
    if(arr[i] > arr[i - 1]) cont;
    ll t = 1ll;
    for(int j = dig(arr[i]); j<dig(arr[i - 1]); j++){
      //moo("%d: %d %d %d\n", i, arr[i], arr[i - 1], t);
      ans++; t *= 10ll;
    }
    //moo("%lld: %lld * %lld\n", arr[i] * t, t, arr[i]);
    if(arr[i] * t > arr[i - 1]){
      //moo("this one\n");
      arr[i] = arr[i] * t;
      cont;
    }
    if(arr[i] < arr[i - 1]/t){ //must still add digit
      moo("this: %lld -> %lld/%lld\n", arr[i], arr[i - 1], t);
      arr[i] = arr[i] * t * 10ll;
      ans++;
      cont;
    }
    ll rem = arr[i - 1] % (arr[i]*t);
    if(dig(rem) != dig(rem + 1ll) && rem != 0){
      //a bunch of 9's
      arr[i] = arr[i] * t * 10ll;
      ans++;
      cont;
    }else{
      moo("wtmoo: %d %d %d\n", rem, arr[i - 1], arr[i] * t);
      arr[i] = arr[i]*t + rem + 1ll;
    }
  }
  for(int i = 0; i<n; i++) moo("%lld\n", arr[i]); mool;
  return ans;
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  for(int i = 1; i<=T; i++){
    moo("Case #%d: %d\n", i, solve());   
  } 
	return 0;
}


