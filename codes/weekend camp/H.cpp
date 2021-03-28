//cash back
//https://codeforces.com/problemset/problem/940/E
//2000 :/
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

ll dp[MX], pre[MX], st[MX * 4], arr[MX];
int n, k, s = 1;
void U(int p, ll val, int k, int L, int R){
  if(p < L || R <= p || R <= L) return ;
  if(L + 1 == R){
    assert(L == p);
    st[k] = val;
    return ;
  }
  int mid = (L + R) /2;
  U(p, val, LC(k), L, mid);
  U(p, val, RC(k), mid, R);
  st[k] = min(st[LC(k)], st[RC(k)]);
}

ll S(int L, int R){
  return pre[R + 1] - pre[L];
}

ll Q(int qL, int qR, int k, int L, int R){
  if(qR <= L || R <= qL || R <= L) return (ll)int_max * (ll)int_max;
  if(qL <= L && R <= qR) return st[k];
  int mid = (L + R)/2;
  return min(Q(qL, qR, LC(k), L, mid), Q(qL, qR, RC(k), mid, R));
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> k;
  while(s <= n) s *= 2;
  init(st, 0x3f);
  init(dp, 0x3f);
  for(int i = 0; i<n; i++){
    cin >> arr[i];
    U(i, arr[i], 0, 0, s);
    pre[i + 1] = pre[i] + arr[i];
  }
  
  dp[0] = 0ll;
  for(int i = 0; i<=n; i++){
    if(i >= 1) dp[i] = min(dp[i], dp[i - 1] + arr[i - 1]);
    if(i >= k) dp[i] = min(dp[i], dp[i - k] + S(i - k, i - 1) - Q(i - k, i, 0, 0, s));
    //moo("i is %d\n", i);
    //moo("\tcase 1: %lld + %lld\n", dp[i - 1], arr[i - 1]);
    //moo("\tcase 2: %lld + %lld - %lld\n", dp[i - k], S(i - k, i - 1), Q(i - k, i, 0, 0, s));
    //moo("\tans: %lld\n", dp[i]);
  }
  moo("%lld\n", dp[n]);
	return 0;
}


