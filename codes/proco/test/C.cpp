//code by me, pst ftw
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
#define int ll
#define lb long double
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ins insert
#define cont continue
#define pow2(n) (1ll << (n))

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
const int MX = 2e5 +10, NLOGN = 4e6, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

//PST SOL????

int sum[NLOGN], lc[NLOGN], rc[NLOGN];
int arr[MX], n, q, s = pow2(30), ind = 0, S, root = 0;

void U(int p, int& k, int L, int R){
  if(p < L || R <= p || R <= L) return ;
  if(!k) k = ++ind; //dup
  if(L + 1 == R){
    orz(L == p);
    sum[k]++;
    return ;
  }
  int mid = (L + R)/2ll;
  U(p, lc[k], L, mid);
  U(p, rc[k], mid, R);
  sum[k] = sum[lc[k]] + sum[rc[k]];
}

int Q(int k, int kth, int L, int R){
  if(L + 1 == R) return L;
  int mid = (L + R)/2ll, dist = sum[lc[k]];
  if(kth >= dist) return Q(rc[k], kth - dist, mid, R);
  else return Q(lc[k], kth, L, mid);
}

signed main(){
  //freopen("in.txt", "r", stdin);
  cin.tie(0) -> sync_with_stdio(0);
  cin >> S >> n;
  while(s<=S) s *= 2ll;
  for(int i = 0; i<n; i++){
    cin >> arr[i];
    U(arr[i], root, 0, s);
  }
  cin >> q;
  while(q--){
    int a; cin >> a;
    moo("%lld\n", min(Q(root, a, 0, s) - 1, S));
  }
  return 0;
}


