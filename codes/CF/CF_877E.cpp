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
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int sum[MX*4], tag[MX*4], trav[MX], r[MX], l[MX];
vector<int> adj[MX];
int n, q, ind, s = 1;

void upd(int k, int L, int R){
  tag[k] ^= 1;
  sum[k] = (R - L) - sum[k];
}

void push(int k, int L, int R){
  int mid = (L + R)/2;
  if(!tag[k]) return;
  upd(LC(k), L, mid);
  upd(RC(k), mid, R);
  tag[k] = 0;
  sum[k] = sum[LC(k)] + sum[RC(k)];
}

void U(int qL, int qR, int k, int L, int R){
  if(qR <= L || R <= qL || R <= L) return ;
  if(qL <= L && R <= qR){
    upd(k, L, R);
    return ;
  }
  int mid = (L + R)/2;
  push(k, L, R);
  U(qL, qR, LC(k), L, mid);
  U(qL, qR, RC(k), mid, R);
  sum[k] = sum[LC(k)] + sum[RC(k)];
}

int S(int qL, int qR, int k, int L, int R){
  if(qR <= L || R <= qL || R <= L) return 0;
  if(qL <= L && R <= qR) return sum[k];
  push(k, L, R);
  int mid = (L + R)/2;
  return S(qL, qR, LC(k), L, mid) + S(qL, qR, RC(k), mid, R);
}

void dfs(int u, int p){
  trav[ind] = u;
  l[u] = ind++;
  for(int v : adj[u]){
    if(v != p) dfs(v, u);
  }
  r[u] = ind; //hmmmmmmmmmmmmmmm
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  while(s<=n) s*=2;
  for(int i = 2; i<=n; i++){
    int a, b = i; cin >> a;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  
  dfs(1, 0);
  for(int i = 1; i<=n; i++){
    int a; cin >> a;
    sum[s + l[i] - 1] = a;
    //if(a) U(l[i], l[i] + 1, 0, 0, s);
    //moo("node %d: %d %d %d\n", i, l[i], r[i], S(l[i], l[i] + 1, 0, 0, s));
  }
  for(int i = s - 2; ~i; i--) sum[i] = sum[LC(i)] + sum[RC(i)];
  //for(int i = 0; i<s + n - 1; i++){
    //moo("%d %d, %d %d\n", i, sum[i], sum[LC(i)], sum[RC(i)]);
  //}
  //for(int i = 0; i<n; i++) moo("%d ", trav[i]); mool;

  cin >> q; //but why
  while(q--){
    char str[10]; int a; cin >> str >> a;
    if(str[0] == 'g'){
      moo("%d\n", S(l[a], r[a], 0, 0, s));
    }else{
      U(l[a], r[a], 0, 0, s);
    }
  }
  return 0;
}


