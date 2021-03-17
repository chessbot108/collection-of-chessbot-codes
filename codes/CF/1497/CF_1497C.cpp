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
#define pow2(n) (1 << (n))
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define init(arr, val, sz) memset(arr, val, sizeof(arr[0]) * (sz))
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

int n, T, k;


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> T;
  while(T--){
    cin >> n >> k;
    if(n%2 == 1){
      moo("%d %d %d\n", 1, n/2, n/2);
    }else if(n%4 == 2){
      moo("%d %d %d\n", 2, n/2 -1, n/2 -1);
    }else{
      moo("%d %d %d\n", n/2, n/4, n/4);
    }
    //fflush(stdout);
  }
	return 0;
}


