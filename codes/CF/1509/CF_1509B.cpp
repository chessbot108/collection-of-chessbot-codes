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
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
  freopen((file_name+".in").c_str(), "r", stdin);
  freopen((file_name+".out").c_str(), "w+", stdout);
}

char str[MX];

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; oom("%d", &T);
  while(T--){
    int n; oom("%d", &n);
    for(int i = 0; i<=n + 12; i++) str[i] = 0;
    oom("%s", str);
    //for(int i = 0; i<n; i++) str[i] = tern(rng()%3, 'T', 'M');
    //moo("%s\n", str);
    assert(strlen(str) == n && n % 3 == 0);
    int tott = 0, totw = 0, wo = 1;
    for(int i = 0; i<n; i++){
      if(str[i] == 'T') tott++;
      else totw++;
      if(totw > tott) wo = 0;
    }

    if(totw * 2 != tott){
      moo("NO\n");
      cont;
    }
    tott = totw = 0; 
    for(int i = n - 1; ~i; i--){
      if(str[i] == 'T') tott++;
      else totw++;
      if(totw > tott) wo = 0;
    }
    
    
    moo("%s\n", tern(wo, "YES", "NO"));
  }
  return 0;
}


