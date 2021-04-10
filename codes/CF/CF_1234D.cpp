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
const int MX = 1e5 +10, sigma = 30, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int BIT[sigma][MX], n;
char str[MX];

int S(int k, int c, int val){ return tern(!k, val, S(k - lsb(k), c, val + BIT[c][k])); }
void U(int k, int c, int val){ for(; k<=n; k+=lsb(k)) BIT[c][k] += val; }

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  oom("%s", str + 1);
  n = strlen(str + 1);
  int q; oom("%d", &q);
  for(int i = 1; i<=n; i++) U(i, str[i] - 'a', 1);
  while(q--){
    int op; oom("%d", &op);
    if(op == 1){
      int k; char s;
      oom("%d %c", &k, &s);
      U(k, str[k] - 'a', -1);
      U(k, s - 'a', 1);
      str[k] = s;
    }else{
      int tot = 0, l, r;
      oom("%d%d", &l, &r);
      for(int i = 0; i<sigma; i++){
        if(S(r, i, 0) - S(l - 1, i, 0) > 0) tot++;
      }
      moo("%d\n", tot);
    }
  }
	return 0;
}


