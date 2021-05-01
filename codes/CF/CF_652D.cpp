//here take a cat
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
#include <set>

#define ll long long
#define lb long double
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ins insert
#define cont continue
#define pow2(n) (1 << (n))

#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define sof(arr) sizeof(arr) //alternative for flexible memset?
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define tern(a, b, c) ((a) ? (b) : (c))
#define feq(a, b) (fabs(a - b) < eps)

#define pbenq priority_queue
#define moo printf
#define oom scanf
#define mool puts("") 
#define loom getline
#define orz assert

const lb eps = 1e-9;
const ll mod = 1e9 + 7;
const int MX = 4e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int srt[MX];
vector<pii> p, t;
int sum[MX * 30], lc[MX * 30], rc[MX * 30], root[MX];

int n, s = 1, ind = 0;

int gind(int k){ return lower_bound(srt + 1, srt + n + n + 1, k) - srt; }

void dup(int& k){
  ind++;
  sum[ind] = sum[k];
  lc[ind] = lc[k];
  rc[ind] = rc[k];
  k = ind;
}

void U(int p, int val, int& k, int L, int R){
  if(R <= p || p < L || R <= L) return ;
  dup(k);
  if(L + 1 == R){
    orz(L == p);
    sum[k] += val;
    return ;
  }
  int mid = (L + R)/2;
  U(p, val, lc[k], L, mid);
  U(p, val, rc[k], mid, R);
  sum[k] = sum[lc[k]] + sum[rc[k]];
}

int S(int qL, int qR, int k, int L, int R){
  if(R <= qL || qR <= L || R <= L) return 0;
  if(qL <= L && R <= qR) return sum[k];
  int mid = (L + R)/2;
  return S(qL, qR, lc[k], L, mid) + S(qL, qR, rc[k], mid, R);
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  while(s<=n*2) s *=2;
  //moo("%d\n", s);
  for(int i = 0; i<n; i++){
    int a, b; cin >> a >> b;
    p.pb(mp(a, b));
    srt[LC(i)] = a;
    srt[RC(i)] = b;
  }
  sort(srt + 1, srt + n + n + 1);
  //for(int i = 1; i<=n*2; i++) moo("%d %d ", srt[i], gind(srt[i])); mool;
  //moo("twmoo\n");
  for(int i = 0; i<n; i++){
    //moo("%d %d\n", p[i].first, p[i].second);
    int a= gind(p[i].first), b = gind(p[i].second);
    p[i] = mp(a, b);
    t.pb(p[i]);
    //moo("%d %d\n", p[i].first, p[i].second);
  }
  //moo("wtmoo\n");
  sort(p.begin(), p.end());
  int i = 0;
  for(int k = 1; k<=n*2; k++){
    root[k] = root[k - 1];
    if(p[i].first == k){
      //moo("%d %d\n", p[i].first, p[i].second);
      U(p[i].second, 1, root[k], 0, s);
      i++;
    }
  }
  /**
  for(int i = 0; i<=n*2; i++){
    for(int j = 0; j<=n*2; j++){
      moo("%3d ", S(0, j, root[i], 0, s));
    } mool;
  }
  **/
  for(int i = 0; i<n; i++){
    moo("%d\n", S(0, t[i].second, root[n * 2], 0, s) - S(0, t[i].second, root[t[i].first], 0, s));

  }
  
  return 0;
}


