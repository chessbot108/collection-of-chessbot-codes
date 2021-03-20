#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>

#define cont continue
#define pow2(n) (1ll << (n))
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))
//geniousity limit exceeded
#define moo printf
#define oom scanf
const ll mod = 1e9 + 7;
const int MX = 1e5 +10, int_max = 0x3f3f3f3f;
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

ll base[5][5], ans[5][5];

void print(ll arr[5][5]){
  moo("%lld %lld\n%lld %lld\n", arr[0][0], arr[0][1], arr[1][0], arr[1][1]);
}

void mmul(ll A[5][5], ll B[5][5]){
  ll C[5][5]; init(C, 0ll);
  //moo("matrix a is\n");
  //print(A); puts("matrix B is:");
  //print(B); puts("matrix C is:");
  for(int i = 0; i<2; i++){
    for(int j = 0; j<2; j++){
      for(int k = 0; k<2; k++){
        C[i][j] = add(C[i][j], mul(A[i][k], B[k][j]));
      }
    }
  }
  for(int i = 0; i<2; i++){
    for(int j = 0; j<2; j++){
      A[i][j] = C[i][j];
    }
  }
  //print(C); puts("");
}


void binpow(ll b){
  base[0][1] = base[1][0] = base[1][1] = ans[0][0] = ans[1][1] = 1;
  for(ll i = 0; pow2(i)<=b; i++){
    //print(base); puts(""); print(ans); puts("");
    if(b&pow2(i)){
      mmul(ans, base);
    }
    mmul(base, base);
  }
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  ll n; cin >> n;
  binpow(n);
  moo("%lld\n", ans[0][1]);
	return 0;
}


