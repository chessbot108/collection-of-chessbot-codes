//IMAGINE NOT KNOWING THAT 7+7 IS 14
//IMAGINE IMAGINE
//n! here we come
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

int perm[MX], arr[MX], n, c, T;


void solve(){
  cin >> n >> c;
  if(n >= 100) moo("this'll TLE for sure\n");
  for(int i = 0; i<n; i++ ) perm[i] = i + 1;
  do{
    for(int i = 0; i<n; i++) arr[i] = perm[i];
    int ans = 0; //borrowed this for my submission for 1
    for(int i = 0; i<n-1; i++){
      int ind = -1;
      for(int j = i; j<n; j++){
        if(ind == -1 || arr[ind] > arr[j]){
          ind = j;
        }
      }
      assert(ind != -1);
      ans += (ind - i) + 1;
      std::reverse(arr + i, arr + ind + 1);
    }
    if(ans == c){
      for(int i = 0; i<n; i++) moo("%d ", perm[i]); mool;
      return ;
    }
  } while(next_permutation(perm, perm + n));
  moo("IMPOSSIBLE\n");
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> T;
  for(int i = 1; i<=T; i++){
    moo("Case #%d: ", i); 
    solve();
  }
	return 0;
}


