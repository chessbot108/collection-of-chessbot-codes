#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <set>

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
#define init(arr, val) memset(arr, val, sizeof(arr))
//geniousity limit exceeded
#define moo printf
#define oom scanf
const ll mod = 1e9 + 7;
const int MX = 1e5 +10, int_max = 0x3f3f3f3f;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int n, q;
multiset<int> ms;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin >> n >> q;
  for(int i = 0; i<n; i++){
    int a; cin >> a;
    ms.insert(a);
  }
  while(q--){
    int a; cin >> a;
    if(ms.count(a)){
      moo("%d\n", a);
      ms.erase(ms.lower_bound(a));
    }else{
      auto it = ms.lower_bound(a);
      if(it == ms.begin()) moo("-1\n");
      else{
        it--; moo("%d\n", *it);
        ms.erase(it);
      }
    }
  }

	return 0;
}


