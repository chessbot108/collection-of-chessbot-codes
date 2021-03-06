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
const int MX = 1e3 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
  freopen((file_name+".in").c_str(), "r", stdin);
  freopen((file_name+".out").c_str(), "w+", stdout);
}

int arr[MX], n, T, k;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> T;
  while(T--){
    cin >> n >> k;
    init(arr, 0);
    for(int i = 0; i<n; i++) cin >> arr[i];
    int eq = n, tot = 0;
    for(int i = 0; i<n; i++){
      if(arr[i] != k) eq--;
      tot += k - arr[i];
    }
    if(eq == n){
      moo("0\n");
    }else if(tot == 0 || (tot && eq)){
      moo("1\n");
    }else{
      moo("2\n");
    }
  }
  return 0;
}


