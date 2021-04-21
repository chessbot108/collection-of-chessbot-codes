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
int arr[MX];
char str[MX];
int n;
int main(){
  cin.tie(0) -> sync_with_stdio(0);
  oom("%d", &n);
  for(int i = 1; i<=n; i++) oom("%d", &arr[i]);
  oom("%s", str + 1);
  //moo("%s\n", str + 1);
  assert(strlen(str + 1) == n - 1);
  int l = 1, r = 0;
  while(l < n){
    for(l = r + 1; str[l] == '0' && l < n; l++){}
    for(r = l; str[r] == '1' && r < n; r++){}
    //moo("%d %d\n", l, r);
    sort(arr+ l, arr + r + 1);
    //for(int i = 1; i<=n; i++) moo("%d ", arr[i]); mool; 
  }
  int wo = 1;
  for(int i = 1; i<=n; i++) wo &= (arr[i] == i);
  moo("%s\n", tern(wo, "YES", "NO"));
  return 0;
}


