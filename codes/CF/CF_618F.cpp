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
const int MX = 1e6 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}
//rng cheese?

vector<pii> a, b;
int n;

void solve(){
  ll sa = 0ll, sb = 0ll; int e = 0;
  for(int i = 0; i<n; i++){
    sb += (ll)b[i].first;
    while(e < n && a[e].first + sa <= sb){
      sa += (ll)a[e].first;
      e++;
    }
    if(sa == sb){
      //moo("%lld %lld\n", sa, sb);
      moo("%d\n", e);
      for(int j = 0; j<e; j++) moo("%d ", a[j].second); mool;
      moo("%d\n", i + 1);
      for(int j = 0; j<=i; j++) moo("%d ", b[j].second); mool;
      exit(0);
    }
  }
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i<n; i++){
    int A; cin >> A;
    a.pb(mp(A, i + 1));
  }
  for(int i = 0; i<n; i++){
    int B; cin >> B;
    b.pb(mp(B, i + 1));
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end()); //but why
  solve();
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  solve();
  for(;;){
    random_shuffle(a.begin(), a.end());
    random_shuffle(b.begin(), b.end());
    solve();
  }
  moo("-1\n");
	return 0;
}


