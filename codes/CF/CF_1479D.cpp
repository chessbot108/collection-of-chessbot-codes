//take 9
//new rng using some c++11 stuff

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
#define pow_2(n) (1 << (n))
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

const ll mod = 1e9 + 7;
const int MX = 6e5 +10, int_max = 0x3f3f3f3f, LOGN = 40;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

//pst op. and editorial op
//the idea is to keep an xor pst 
//and big brain proof, which is somewhat intuitive
//that it'll work

ll sum[MX * LOGN], nw[MX];
int rc[MX * LOGN], lc[MX * LOGN];
int arr[MX], root[MX];
int n, q, s = 1, ind, t_ind;

int super[MX][30], dep[MX], trav[MX]; //when you need lca too
vector<int> adj[MX];
void dup(int& k){
  sum[++ind] = sum[k];
  lc[ind] = lc[k];
  rc[ind] = rc[k];
  k = ind;
}

void U(int p, int& k, ll val, int L, int R){
  dup(k);
  if(L + 1 == R){
    assert(L == p);
    sum[k] ^= val;
    return ;
  }
  int mid = (L + R)/2;
  if(p < mid) U(p, lc[k], val, L, mid);
  else U(p, rc[k], val, mid, R);
  sum[k] = sum[lc[k]] ^ sum[rc[k]];
}

int bin_search(int k1, int k2, int l, int p, int L, int R){
  if(L + 1 == R) return L;
  int mid = (L + R)/2;
  //printf("%20lld%20lld%20lld%20lld%4d%4d%4d%4d\n", sum[k1], sum[k2], sum[p], sum[l], k1, k2, p, l);
  if(sum[lc[k1]]^sum[lc[k2]]^sum[lc[l]]^sum[lc[p]])
    return bin_search(lc[k1], lc[k2], lc[l], lc[p], L, mid);
  else
    return bin_search(rc[k1], rc[k2], rc[l], rc[p], mid, R);
}

//true pain
//8 param segtree function here i come
int Q(int qL, int qR, int k1, int k2, int l, int p, int L, int R){
  //cout << qL << " " << qR << " " << L << " " << R << endl;
  if(R <= qL || qR <= L || R <= L) return -1;
  if(qL <= L && R <= qR){
    if(sum[k1]^sum[k2]^sum[l]^sum[p]) return bin_search(k1, k2, l, p, L, R);
    else return -1;
  }
  int mid = (L + R)/2;
  
  return max(Q(qL, qR, lc[k1], lc[k2], lc[l], lc[p], L, mid), Q(qL, qR, rc[k1], rc[k2], rc[p], rc[l], mid, R));
}

void dfs(int u, int p, int d){
  super[u][0] = p;
  dep[u] = d;
  trav[t_ind++] = u;
  for(int v : adj[u]){
    if(v != p)
      dfs(v, u, d + 1);
  }
}

int k_up(int u, int k){
  for(int i = 25; ~i; i--){
    if(pow_2(i) <= k) k = k - pow_2(i), u = super[u][i];
  }
  return u;
}

int lca(int u, int v){
  if(dep[u] < dep[v]) swap(u, v);
  u = k_up(u, dep[u] - dep[v]);
  if(u == v) return u;
  for(int i = 25; ~i; i--){
    if(super[u][i] != super[v][i]) u = super[u][i], v = super[v][i];
  }
  assert(super[u][0] != 0);
  assert(super[u][0] == super[v][0]);
  return super[u][0];
}

void precomp(){
  dfs(1, 0, 0);
  for(int j = 1; pow_2(j) <= n; j++){
    for(int i = 1; i<=n; i++){
      super[i][j] = super[super[i][j - 1]][j - 1];
    }
  }
  //lca done
  //pst precomp
  while(s <= n) s *= 2;
  for(int t = 0; t<t_ind; t++){
    int i = trav[t];
    //cout << i << " " << super[i][0] << endl;
    root[i] = root[super[i][0]];
    U(arr[i], root[i], nw[arr[i]], 0, s);
  }
}



int main(){
	cin.tie(0) -> sync_with_stdio(0);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin >> n >> q;
  for(int i = 1; i<=n; i++){
    cin >> arr[i];
    if(!nw[arr[i]]) nw[arr[i]] = rng();
  }
  for(int i = 1; i<n; i++){
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  precomp();
  while(q--){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int l = lca(a, b), p = super[l][0];
    //cout << a << " " << b << " " << l << " " << p << endl;
    cout << Q(c, d + 1, root[a], root[b], root[l], root[p], 0, s) << '\n';
  }

	return 0;
}


