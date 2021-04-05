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
const int MX = 1e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}
char str[MX];
int pre[MX], suf[MX], n;

int main(){
  cin.tie(0) -> sync_with_stdio(0);

  oom("%d%s", &n, str);
  //moo("%s -> %d\n", str, n);

  for(int i = 0; i<=n-5; i++){
    pre[i] = 1;
    for(int j = 0; j<5; j++){
      if(str[i + j] != (char)('0' + j)) pre[i] = 0;
    }
    //if(pre[i]) moo("pre -> %d\n", i);
  }
  
  for(int i = 0; i<=n-5; i++){
    suf[i] = 1;
    for(int j = 0; j<5; j++){
      if(str[i + j] != (char)('5' + j)) suf[i] = 0;
    }
    //if(suf[i]) moo("suf -> %d\n", i);
  }
  ll ans = 0ll, cnt = 0ll;
  for(int i = 0; i<n; i++){
    cnt += (ll)pre[i];
    if(suf[i]) ans += cnt;
  }
  moo("%lld\n", ans);
	return 0;
}


