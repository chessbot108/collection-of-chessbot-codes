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
#define init(arr, val) memset(arr, val, sizeof(arr))
#define bckt(arr, val, sz) memset(arr, val, sizeof(arr[0]) * (sz))
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define tern(a, b, c) ((a) ? (b) : (c))
#define feq(a, b) (fabs(a - b) < eps)

#define moo printf
#define oom scanf
#define mool puts("") 
#define orz assert
#define fll fflush(stdout)

const lb eps = 1e-9;
const ll mod = 1e9 + 7, ll_max = (ll)1e18;
const int MX = 4e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll sum[MX], d[MX], ind[MX], arr[MX];
int n, q, s = 1;
void U(int p, ll v, int k, int L, int R){
  if(p < L || R <= p || R <= L) return ;
  if(L + 1 == R){
    orz(L == p);
    sum[k] = d[k] = v;
    ind[k] = p; //i mean...
    return ;
  }
  int mid = (L + R)/2;
  U(p, v, LC(k), L, mid);
  U(p, v, RC(k), mid, R);
  sum[k] = sum[LC(k)] + sum[RC(k)];
  d[k] = max(d[LC(k)], d[RC(k)]);
  ind[k] = tern(d[LC(k)] >= d[RC(k)], ind[LC(k)], ind[RC(k)]); //moorz
}

ll S(int qL, int qR, int k, int L, int R){
  if(qR <= L || R <= qL || R <= L) return 0ll;
  if(qL <= L && R <= qR) return sum[k];
  int mid = (L + R)/2;
  return S(qL, qR, LC(k), L, mid) + S(qL, qR, RC(k), mid, R);
}

int Q(int qL, int qR, int k, int L, int R){
  if(qR <= L || R <= qL || R <= L) return MX-1; //this should be 0 right....
  if(qL <= L && R <= qR) return ind[k];
  int mid = (L + R)/2, i1 = Q(qL, qR, LC(k), L, mid), i2 = Q(qL, qR, RC(k), mid, R);
  return tern(arr[i1] > arr[i2], i1, i2);
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> q;
  while(s<=n) s*=2;
  for(int i = 0; i<n; i++) cin >> arr[i];
  for(int i = 0; i<n; i++) U(i, arr[i], 0, 0, s);
  while(q--){
    int op; cin >> op;
    if(op == 1){
      int a, b; cin >> a >> b;
      moo("%lld\n", S(a - 1, b, 0, 0, s));
    }else if(op == 3){
      int a, b; cin >> a >> b;
      arr[a - 1] = b;
      U(a - 1, (ll)b, 0, 0, s);
    }else{
      int a, b; ll x; cin >> a >> b >> x;
      int k = Q(a - 1, b, 0, 0, s);
      while(arr[k] >= x){
        //moo("%d >%d %lld\n", x, k, arr[k]);
        arr[k]%=x;
        U(k, arr[k], 0, 0, s);
        k = Q(a - 1, b, 0, 0, s);
      }
      //moo("%d >%d %lld\n", x, k, arr[k]);
    }
    //for(int i = 0; i<n; i++) moo("%lld ", arr[i]); mool;
  }
  return 0;
}


