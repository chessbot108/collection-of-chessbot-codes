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
#include <set>

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

int n, x;
multiset<int> ms;


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> x;
  for(int i = 0; i<n; i++){
    int a; cin >> a;
    ms.ins(a);
  }
  int ans = 0;
  while(!ms.empty()){
    auto it = --ms.end();
    if(*it <= x/2){ //it doesnt matter who i pair it with
      if(ms.size() != 1) ms.erase(ms.begin());
      ms.erase(it);
    }else{
      auto it2 = ms.lower_bound(x - (*it));
      assert(it2 != ms.end());
      if((*it) + (*it2) <= x) ms.erase(it2);
      else if(!(it2 == ms.begin() && (*it2) + (*it) > x)){
        ms.erase(--it2);
      }
      ms.erase(it);
    }
    ans++;
  }
  moo("%d\n", ans + (int)ms.size());
	return 0;
}


