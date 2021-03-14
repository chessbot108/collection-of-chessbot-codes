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
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

//really standard HLD impl. so imma do just that
int par[MX], super[MX], trav[MX], ord[MX], dep[MX], son[MX], sub[MX], rep[MX]; //i see, and this isnt even the segtree
int st[MX*4];
int arr[MX], n, q, s = 1, ind;
vector<int> adj[MX];

void U(int p, int val, int k, int L, int R){
  if(L + 1 == R){
    //assert(L == p);
    st[k] = val;
    return ;
  }
  int mid = (L + R)/2;
  if(p < mid) U(p, val, LC(k), L, mid);
  else U(p, val, RC(k), mid, R);
  st[k] = max(st[LC(k)], st[RC(k)]);
}

int Q(int qL, int qR, int k, int L, int R){
  if(qR <= L | R <= qL) return 0;
  if(qL <= L && R <= qR) return st[k];
  int mid = (L + R)/2;
  return max(Q(qL, qR, LC(k), L, mid), Q(qL, qR, RC(k), mid, R));
}

void dfs(int u, int p){
  //moo("%d %d %d\n", u, p, d);
  par[u] = p;
  dep[u] = dep[p] + 1;
  sub[u] = 1;
  for(int v : adj[u]){
    if(v == p) cont;
    dfs(v, u);
    sub[u] += sub[v];
    if(!son[u] || sub[son[u]] < sub[v]) son[u] = v;
  }
}

void decomp(int u, int r){
  trav[u] = ind;
  ord[ind++] = u;
  rep[u] = r;
  if(son[u] != 0){
    decomp(son[u], r);
  }
  for(int v : adj[u]){
    if(v != son[u] && v != par[u]) decomp(v, v); //seems legit
  }
}

int work(int x, int y){
  int ans = 0;
  while(rep[x] != rep[y]){
    if(dep[rep[x]] < dep[rep[y]]) swap(x, y);
    ans = max(ans, Q(trav[rep[x]], trav[x] + 1, 0, 0, s)); //note the +1 since my segtree is [l, r)
    x = par[rep[x]];
  }
  if(rep[x] == rep[y]){
    ans = max(ans, Q(min(trav[x], trav[y]), max(trav[x], trav[y]) + 1, 0, 0, s));
  }
  return ans;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin >> n >> q;
  while(s <= n) s *= 2;
  for(int i = 1; i<=n; i++){
    //oom("%d", &arr[i]);
    cin >> arr[i];
  }
  
  for(int i = 1; i<n; i++){
    int a, b; 
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  //moo("input done\n");
  dfs(1, 0);
  decomp(1, 1);
  //moo("precomp don\n");
  
  
  for(int i = s - 1; i < (s + n - 1); i++){
    st[i] = arr[ord[i - (s - 1)]];
  }
  for(int i = s - 2; ~i; i--){
    st[i] = max(st[LC(i)], st[RC(i)]);
  }
  
  
  while(q--){
    int op, a, b; //oom("%d%d%d", &op, &a, &b);
    cin >> op >> a >> b;
    if(op == 1){
      U(trav[a], b, 0, 0, s);
    }else{
      cout << work(a, b) << '\n';
    }
  }
  
  return 0;
}


