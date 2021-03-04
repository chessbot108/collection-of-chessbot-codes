//I DID IT
//TERNARY RANGE BASED FOR LOOP AC
//:OOOOOOOOOOOOOOOOOOOOOOOOOOO
//IT WAS THE SORTING OPERATOR REEEEEEEEEEE
//TY BCKT I WOULDNT HAVE FOUND THE BUG OTHERWISE

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <functional>
#define int ll
#define int_max 0x3f3f3f3f
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
const int max_v = 1e6 +10;
using namespace std;
 
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}
 
int par[max_v], sz[max_v], arr[max_v];
pii srt[max_v];
int n;
vector<int> adj[max_v], adj2[max_v];
 
int find(int x){
  if(x != par[x]) par[x] = find(par[x]);
  return par[x];
}
 
void Union(int a, int b){
  a = find(a), b = find(b);
  if(a == b) return ;
  if(sz[a] > sz[b]) swap(a, b);
  sz[b] += sz[a];
  par[a] = b;
}
 
void make_tree(){
  for(int i = 0; i<=n; i++){
    par[i] = i;
    sz[i] = 1;
  }
} 
 
bool cmp(const pii& a, const pii& b){
  return a.first > b.first || (a.first == b.first && a.second < b.second);
}
 
ll solve(int op){
  if(op == 1) sort(srt, srt + n, greater<pii>());
  else sort(srt, srt + n);
  make_tree();
  ll tot = 0ll;
  for(int i = 0; i<n; i++){
    
    int u = srt[i].second;
    ll fac = (ll)srt[i].first, res = 1ll;
    //cout << i << " " << u << " " << fac << " " << tot << endl;
    //cout << "\tpaths that end at " << u << endl;
    for(int v : (op ? adj[u] : adj2[u])){
      if(find(v) == find(u)) cont; 
      res += (ll)sz[find(v)];
      //cout << "\t" << v << " " << sz[find(v)] << endl;
    }
    //cout << "\tpaths that go through " << u << endl;
    ll psum = 0ll;
    for(int v : (op ? adj[u] : adj2[u])){
      //cout << "\t" << v <<  " " << sz[find(v)] << " " << psum << endl;
      if(find(v) == find(u)) cont; 
      res += psum * (ll)sz[find(v)];
      psum += (ll)sz[find(v)];
    }
    //cout << "\t" << res << " " << fac << endl;
    tot += res * fac;
    for(int v : (op ? adj[u] : adj2[u])){
      if(find(v) == find(u)) cont; 
      Union(u, v);
    }
  }
  return tot;
}
 
 
signed main(){
	cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i<=n; i++){
    cin >> arr[i];
    srt[i - 1] = mp(arr[i], i);
  }
  for(int i = 1; i<n; i++){
    int a, b;
    cin >> a >> b;
    if(arr[a] < arr[b]) adj[a].pb(b);
    if(arr[b] < arr[a]) adj[b].pb(a);
    if(arr[a] > arr[b]) adj2[a].pb(b);
    if(arr[b] > arr[a]) adj2[b].pb(a);
    if(arr[a] == arr[b]){
      //if(a < b){
        //adj[a].pb(b);
        adj2[max(a, b)].pb(min(a, b));
      //}else{
        adj[min(a, b)].pb(max(a, b));
        //adj2[b].pb(a);
      //}
    }
    //stolen from bckt
  }
  ll ans = solve(0) - solve(1);
  cout << ans << endl;
	return 0;
}
 
