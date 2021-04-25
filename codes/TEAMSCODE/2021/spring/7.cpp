//code by me

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

#define cont continue
#define pow2(n) (1 << (n))
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ins insert

#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define tern(a, b, c) ((a) ? (b) : (c))

#define pbenq priority_queue
#define moo printf
#define oom scanf
#define mool puts("") 
#define loom getline
#define orz assert

const ll mod = 1e9 + 7;
const int MX = 2e6 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
  freopen((file_name+".in").c_str(), "r", stdin);
  freopen((file_name+".out").c_str(), "w+", stdout);
}

int sz[MX], par[MX], n, m, k;
vector<int> adj[MX];


void mkdsu(){ for(int i = 0; i<=k; i++) sz[i] = 1, par[i] = i; }
int fin(int x){ if(x != par[x]) par[x] = fin(par[x]); return par[x]; }
void Union(int a, int b){
  a = fin(a), b = fin(b);
  if(a == b) return ;
  if(sz[a] < sz[b]) swap(a, b);
  sz[a] += sz[b];
  par[b] = a;
}
int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  k = n*n;
  mkdsu();
  for(int i = 0; i<m; i++){
    int a, b, c, d; cin >> a >> b >> c >> d;
    a--, b--, c--, d--;
    Union(a*n +b, c*n +d);
  }
  ll tot =0;
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){ 
      tot += sz[fin(i*n +j)];
    }   
  }
  moo("%lld\n", tot);
  return 0;
}


