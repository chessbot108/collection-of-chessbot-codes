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
#include <functional>
#include <set>

#define cont continue
#define pow2(n) (1 << (n))
#define ll long long
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
const int MX = 1e2 +10, MAXI = 2e3, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
  freopen((file_name+".in").c_str(), "r", stdin);
  freopen((file_name+".out").c_str(), "w+", stdout);
}

int dp[MX * MAXI], arr[MX], s = 0;

vector<pii> vec;
bool comp(const pii& a, const pii& b){
  return a.first > b.first;
}

bool brute(){
  s = 0;
  for(int i = 0; i<6; i++) if(arr[i] < 1e6) s += arr[i];
  for(int i = 0; i<pow2(6); i++){
    int S = 0;
    for(int j = 0; j<6; j++){
      if(pow2(j)&i) S += arr[j];
    }
    if(s - S == S){
      moo("%d, %d %d %d\n", i, s - S, S, s);
      return 1;
    }
  }
  return 0;
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 0; i<n; i++){
    cin >> arr[i];
    //arr[i] = rng() %10 +1;
    //moo("%d ", arr[i]);
    s += arr[i];
  }
  orz(s <= MX * MAXI);
  for(int i = 0; i<n; i++) vec.pb(mp(arr[i], i));
  sort(vec.begin(), vec.end(), greater<pii>());
  dp[0] = 1;
  for(int j = 0; j<n; j++){
    int i = vec[j].second, a = vec[j].first;
    for(int k = s; k >= a; k--){
      if(dp[k - a]) dp[k]  = 1;
    }
  }
  
  if(s%2 == 1 || dp[s/2] == 0){
    //if(brute()) moo("exp 1, got 0");
    moo("0\n");
  }else{
    //arr[vec[0].second] = 1e6; //INF
    //s = 0;
    //if(brute()) moo("exp 0, got 1");
    while(1){
      for(int i = 0; i<n; i--){
        if(vec[i].first%2 != 0){
          moo("1\n%d\n", vec[i].second);
          return 0;
        }
        vec[i].first /= 2;
      }
    }
  }
  return 0;
}


