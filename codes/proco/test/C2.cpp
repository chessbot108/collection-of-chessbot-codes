//here take a cat
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
#include <map>
#include <iterator>

#define ll long long
#define lb long double
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ins insert
#define cont continue
#define pow2(n) (1 << (n))

#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define bckt(arr, val, sz) memset(arr, val, sizeof(arr[0]) * (sz))
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define tern(a, b, c) ((a) ? (b) : (c))
#define feq(a, b) (fabs(a - b) < eps)

#define moo printf
#define oom scanf
#define mool puts("") 
#define orz assert
#define fll fflush(stdout)

const lb eps = 1e-9;
const ll mod = 1e9 + 7, ll_max = (ll)1e18;
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

set<int> srt;
map<int, int> freq;
int n, q, s, arr[MX], push[MX];


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >>s >> n;
  for(int i = 0; i<n; i++){
    int a; cin >> a;
    srt.ins(a);
    freq[a]++;
  }
  for(auto it = next(srt.begin()); it != srt.end(); it++){
    auto p = prev(it);
    freq[*it] += freq[*p];
  }
  auto IT = srt.begin();
  for(int i = 0; i<srt.size(); i++){
    arr[i] = *IT;
    push[i] = freq[*IT];
    IT++;
  }
  cin >> q;
  while(q--){
    int a; cin >> a;
    int i = lower_bound(push, push + (int)(srt.size()), a) - push;
    moo("%d\n", arr[i] - 1);
  }
  return 0;
}


