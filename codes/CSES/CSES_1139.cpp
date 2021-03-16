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

int arr[MX], srt[MX], trav[MX*2], BIT[MX *2], occ[MX], L[MX], R[MX], ans[MX], n, ind;
vector<int> adj[MX];

int S(int k, int T = 0){ return (!k) ? T : S(k - lsb(k), BIT[k] + T);}
void U(int k, int val){ for(; k<=n*2; k += lsb(k)) BIT[k] += val; }

void dfs(int u, int p){
  trav[++ind] = u;
  L[u] = ind;
  for(int v : adj[u]){
    if(v != p)
      dfs(v, u);
  }
  trav[++ind] = -u;
  R[u] = ind;
}



int main(){
  cin.tie(0) -> sync_with_stdio(0);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  
  oom("%d", &n);
  for(int i = 1; i<=n; i++){
    oom("%d", &arr[i]);
  }
  
  for(int i = 1; i<n; i++){
    int a, b; oom("%d%d", &a, &b);
    adj[a].pb(b);
    adj[b].pb(a);
  } 
  
  for(int i = 1; i<=n; i++) srt[i] = arr[i];
  sort(srt + 1, srt + n + 1);
  for(int i = 1; i<=n; i++) arr[i] = lower_bound(srt + 1, srt + n + 1, arr[i]) - &srt[0];
  
  dfs(1, 0);
  
  //for(int i = 1; i<=n*2; i++) moo("%3d", trav[i]); puts("");

  for(int i = 1; i<=n*2; i++){
    int u = trav[i];
    if(u > 0){ //left endpoint
      if(occ[arr[u]]){
        U(occ[arr[u]], -1);
      }
      U(L[u], 1);
      occ[arr[u]] = L[u]; 
    }else{ //right side
      u = -u;
      ans[u] = S(R[u]) - S(L[u] - 1);
    }
    //for(int k = 1; k<=n; k++) moo("%d %d\n", k, occ[k]);
    //puts("\n");
  } 
  
  for(int i = 1; i<=n; i++){
    moo("%d ", ans[i]);
  }
  puts("");
	return 0;
}


