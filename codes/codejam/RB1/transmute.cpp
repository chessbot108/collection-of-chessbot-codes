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
const int MX = 1e4 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
  freopen((file_name+".in").c_str(), "r", stdin);
  freopen((file_name+".out").c_str(), "w+", stdout);
}

int arr[MX], need[MX];


int solve(){
  init(arr, 0);
  int n, a, b, h; cin >> n >> a >> b;
  for(int i = 1; i<=n; i++){
    cin >> arr[i];
    need[i] = arr[i];
    if(arr[i]) h = i;
  }

  int x = 1;
  
  while(1){
    //if(x >= 20) break;
    //moo("%d\n", x);
    //for(int i = 1; i<=n*2; i++){
      //moo("%3d ", arr[i]);
    //} mool;
    for(int i = x; i<=n*100; i++){
      if(arr[i]) h = i;
    }
    if(x == h && arr[x] == 1) break;
    if(arr[x] <= arr[x + 1]){
      arr[x + 2] += arr[x];
      arr[x + 1] -= arr[x];
      arr[x] = 0;
      //h = max(x + 2, h);
    }else{
      arr[x + 2] += arr[x + 1];
      arr[x] -= arr[x + 1];
      arr[x + 1] = 0;
      //h = max(x + 2, h);
    }
    if(arr[x]%2){
      arr[x]--;
      arr[x + 1]++;
      h = max(x + 1, h);
      if(arr[x]){
        arr[x]--, arr[x + 1]--;
        arr[x + 2]++;
        //h = max(x + 2, h);
      }
    }
    //if(arr[x]) h = max(x + 2, h);
    arr[x + (arr[x] - 1)]++;
    arr[x] = 0;
    x++;
  }
  return x; 
}



int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  for(int i = 1; i<=T; i++){
    moo("Case #%d: %d\n", i, solve());
  }
  return 0;
}


