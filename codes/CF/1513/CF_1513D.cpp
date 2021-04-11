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
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}
int arr[MX], dist[MX], par[MX], sz[MX];
int n, p;
vector<pii> vec;

int find(int x){ if(x != par[x]) par[x] = find(par[x]); return par[x]; }
void mkdsu(){ for(int i = 0; i<=n; i++) par[i] = i, sz[i] = 1, dist[i] = 0; }
void Union(int a, int b){
  a = find(a), b = find(b);
  if(a == b) return ;
  if(sz[a] < sz[b]) swap(a, b);
  sz[a] += sz[b];
  par[b] = a;
}

int gcd(int a, int b){
  return tern(!b, a, gcd(b, a%b));
}

ll solve(){
  cin >> n >> p;
  vec.clear();
  for(int i = 0; i<n; i++){
    cin >> arr[i];
    vec.pb(mp(arr[i], i));
  }
  mkdsu();
  sort(vec.begin(), vec.end());
  ll tot = 0ll;
  for(int i = 0; i<n; i++){
    int w = vec[i].first, u = vec[i].second;
    dist[u] = w;
    //moo("u, w -> %d %d\n", u, w);
    if(w > p) cont;
    for(int v = u + 1; v<n; v++){
      //moo("\tv, arr[v], %d %d\n",v, arr[v]);
      if(gcd(arr[v], w) != w) break;
      if(find(u) != find(v)) tot += (ll)w;
      else break;
      Union(u, v);
      dist[v] = w;
    }
    for(int v = u - 1; v >= 0; v--){
      //moo("\tv, arr[v], dist[v], %d %d %d\n", v, arr[v], dist[v]);
      if(gcd(arr[v], w) != w) break;
      if(find(u) != find(v)) tot += (ll)w;
      else break;
      Union(u, v);
      dist[v] = w;
    }
  }
  for(int i = 0; i<n-1; i++){
    if(find(i) != find(i + 1)){
      tot += (ll)p;
      Union(i, i + 1);
    }
  }
  return tot;
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--){
    moo("%lld\n", solve());
  }
	return 0;
}


