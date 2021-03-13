#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
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
#define init(arr, val) memset(arr, val, sizeof(arr))
//geniousity limit exceeded
#define moo printf
#define oom scanf
const ll mod = 1e9 + 7;
const int MX = 1e5 +10, int_max = 0x3f3f3f3f;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int super[MX][30]; //lca
int BIT[MX*2], trav[MX*2], L[MX], R[MX], dep[MX];
int n, q, arr[MX], ind = 0;
vector<int> adj[MX];

int S(int k){ return (!k) ? 0 : (BIT[k]^S(k - lsb(k)));}
void U(int k, int val){ for(; k<=n*2; k += lsb(k)) BIT[k] ^= val; }

void dfs(int u, int p, int d){
  super[u][0] = p;
  dep[u] = d;
  trav[++ind] = u;
  L[u] = ind;
  for(int v : adj[u]){
    if(v != p)
      dfs(v, u, d + 1);
  }
  trav[++ind] = u;
  R[u] = ind;
}

void precomp(){
  for(int j = 1; pow2(j) <=n; j++){
    for(int i = 1; i<=n; i++){
      super[i][j] = super[super[i][j - 1]][j - 1];
    }
  }
}

int k_up(int u, int k){
  for(int j = 27; ~j; j--){
    if(pow2(j) <= k) k = k - pow2(j), u = super[u][j];
  }
  return u;
}

int lca(int a, int b){
  if(dep[a] > dep[b]) swap(a, b);
  b = k_up(b, dep[b] - dep[a]);
  if(a == b) return a;
  for(int j = 27; ~j; j--){
    //moo("a and b: %d %d\n", a, b);
    if(super[a][j]^super[b][j]) a = super[a][j], b = super[b][j];
  }
  assert(a != b && super[a][0] != 0);
  return super[a][0];
}

int Q(int a, int b){
  int l = lca(a, b), p = super[l][0];
  return S(L[a])^S(L[b])^S(L[l])^S(L[p]);
}

void print(){
  for(int i = 1; i<=n*2; i++) moo("%d ", trav[i]); puts("");
  for(int i = 1; i<=n; i++){
    moo("node: %d\n\theight: %d\n\tpar: %d\n", i, dep[i], super[i][0]);
  }
  puts("\n");
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  setIO("cowland");
  oom("%d%d", &n, &q);
  for(int i = 1; i<=n; i++) oom("%d", &arr[i]);
  for(int i = 1; i<n; i++){
    int a, b;
    oom("%d%d", &a, &b);
    adj[a].pb(b);
    adj[b].pb(a);
  }
  dfs(1, 0, 0);
  precomp();
  for(int i = 1; i<=n; i++){
    U(L[i], arr[i]);
    U(R[i], arr[i]);
  }
  //print(); 
  while(q--){
    int op, a, b; oom("%d%d%d", &op, &a, &b);
    if(op == 1){
      b ^= arr[a];
      U(L[a], b);
      U(R[a], b);
      arr[a] ^= b;
    }else{
      moo("%d\n", Q(a, b));
    }
  }

	return 0;
}


