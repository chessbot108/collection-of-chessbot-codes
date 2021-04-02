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
const int MX = 8e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
  freopen((file_name+".in").c_str(), "r", stdin);
  freopen((file_name+".out").c_str(), "w+", stdout);
}
//purplecrayon OTZ
//segtree on tree dark magic
//the shame cube algorithm
//https://codeforces.com/blog/entry/68676?#comment-530605

ll dep[MX], m[MX], ab[MX], bc[MX], abc[MX], tag[MX], arr[MX];
int L[MX], R[MX], pos[MX]; //tree traversal
int n, q, ind = 0, s = 1; ll w;
vector<pii> adj[MX]; //node, input index

void push(int k, ll val){
  dep[k] += val;
  m[k] -= 2ll*val;
  ab[k] -= val;
  bc[k] -= val;
  tag[k] += val;
  //moo("PUSH: %d %lld :-> (%lld %lld %lld %lld), %lld\n", k, val, dep[k], ab[k], bc[k], m[k], abc[k]);
} //push down type vibes

void Union(int k){
  int l = LC(k), r = RC(k);
  dep[k] = max(dep[l], dep[r]);
  m[k] = max(m[l], m[r]);
  ab[k] = max({ab[l], ab[r], dep[l] + m[r]});
  bc[k] = max({bc[l], bc[r], m[l] + dep[r]});
  abc[k] = max({abc[l], abc[r], dep[l] + bc[r], ab[l] + dep[r]});
  //moo("%d %lld :-> (%lld %lld %lld %lld), %lld\n", k, val, dep[k], ab[k], bc[k], m[k], abc[k]);
} //literally dark magic. dont question it


void U(int qL, int qR, int k, ll val, int L, int R){
  if(R <= qL || qR <= L || R <= L) return ;
  //moo("\t\t%d -> [%d, %d]\n", k, L, R);
  if(qL <= L && R <= qR){
    push(k, val);
    return ;
  }
  if(tag[k]){ //push down add tag :/
    push(LC(k), tag[k]);
    push(RC(k), tag[k]);
    tag[k] = 0;
  }
  int mid = (L + R)/2;
  U(qL, qR, LC(k), val, L, mid);
  U(qL, qR, RC(k), val, mid, R);
  Union(k);
  //moo("%d [%d, %d] %lld :-> (%lld %lld %lld %lld), %lld\n", k, L, R, val, dep[k], ab[k], bc[k], m[k], abc[k]);

}

void dfs(int u, int p){
  L[u] = ind++;
  for(const pii& e : adj[u]){
    if(e.first == p) cont;
    pos[e.second] = e.first;
    dfs(e.first, u);
    ind++;
  }
  R[u] = ind;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> q >> w;
  for(int i = 1; i<n; i++){
    int a, b; ll c;
    cin >> a >> b >> c;
    adj[a].pb(mp(b, i));
    adj[b].pb(mp(a, i));
    arr[i] = c;
  }
  dfs(1, 0);
  while(s<=ind) s*=2;
  for(int i = 1; i<n; i++){
    U(L[pos[i]], R[pos[i]], 0, arr[i], 0, s);
  }
  /** 
  for(int i = 1; i<n; i++){
    moo("%d -> %d [%d %d], %lld\n", i, pos[i], L[pos[i]], R[pos[i]], arr[i]);
  }
  **/
  //moo("%lld\n", abc[0]); 
  ll last = 0ll;
  while(q--){
    ll a, b; 
    cin >> a >> b;
    a = (a + last)% (ll)(n - 1) +1;
    b = (b + last)% w;
    //moo("%d %lld\n", a, b);
    U(L[pos[a]], R[pos[a]], 0, b - arr[a], 0, s);
    last = abc[0];
    arr[a] = b;
    moo("%lld\n", last);
  }
  return 0;
}


