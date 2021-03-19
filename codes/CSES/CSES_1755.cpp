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
const int MX = 1e6 +10, int_max = 0x3f3f3f3f;
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int freq[MX], n, odd;
char str[MX], ans[MX];

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  oom("%s", str); n = strlen(str);
  for(int i = 0; i<n; i++){
    freq[str[i]]++;
  }
  for(int i = 'A'; i <= 'Z'; i++){
    odd += (freq[i])%2;
  } 
  if(odd >= 2) moo("NO SOLUTION\n");
  else{
    int s = 0;
    for(int i = 'A'; i <= 'Z'; i++){
      if(freq[i]%2 == 1){
        ans[n/2] = char(i);
        freq[i]--;
      }
      while(freq[i] > 0){
        ans[s] = ans[(n - s) - 1] = char(i); s++; freq[i] -= 2;
      }
    }
    moo("%s\n", ans);
  }
	return 0;
}


