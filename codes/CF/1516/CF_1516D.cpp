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
const int MX = 2e5 +10, LOGN = 40, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
  freopen((file_name+".in").c_str(), "r", stdin);
  freopen((file_name+".out").c_str(), "w+", stdout);
}

int super[MX][LOGN];

int occ[MX], low[MX], vis[MX], arr[MX];
int n, q;
vector<int> fac[MX];

void precomp(){
  for(int i = 2; i<=1e5; i++){
    if(!vis[i] && (ll)i * (ll)i <= 1e5){
      low[i] = i;
      for(int j = i*i; j<=1e5; j += i) if(!vis[j]) vis[j] = low[j] = i;
    }
  }
}




int main(){
  cin.tie(0) -> sync_with_stdio(0);
  precomp();
  cin >> n >> q;
  for(int i = 0; i<n; i++){
    cin >> arr[i];
    moo("%d %d\n", i, arr[i]);
    for(int j = arr[i]; j != 1; j/=low[j]){
      fac[i].pb(low[j]);
      moo("\t%d\n", low[j]);
    }
  }
  int r = 0;
  for(int i = 0; i<n; i++){
    while(r < n){
      moo("%d %d, %d %d\n", i, r, arr[i], arr[r]);
      int wo = 0;
      for(int v : fac[i]) if(occ[v]) wo = 1;
      if(wo) break;
      for(int v : fac[i]){
        moo("\t%d %d\n", v, occ[v]);
        occ[v]++;
      }
      r++;
    }
    super[i][0] = r;
    for(int v : fac[i]) occ[v]--;
  }
  for(int i = 0; i<n; i++) moo("%d \n", super[i][0]); mool;
  return 0;
}


