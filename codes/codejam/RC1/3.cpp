
//brute force needed. probably a bfs
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
#define int long //ARE YOU READY FOR WAR CRIMES WITH ME
#define moorz multiset
#define apple multimap
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

#define pbenq priority_queue
#define moo printf
#define oom scanf
#define mool puts("") 
#define loom getline
#define orz assert
//what if using geniousities in my macros
//will boost my chances at ac?
//might as well try it out

const lb eps = 1e-9;
const ll mod = 1e9 + 7;
const int MX = 4e6 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int dist[MX], vis[MX];

int NO(int k){
  if(k == 0) return 1;
  int d = 0, ans = 0;
  for(int i = 30; ~i; i--){
    if(k&pow2(i)){
      d = 1;
    }else if (d){
      ans += pow2(i);
    }
  }
  return ans;
}

int input(){
  string str; cin >> str;
  int val = 0;
  for(int i = 0; i < (int)str.size(); i++) val += (str[(str.size() - 1)- i] - '0') * pow2(i);
  return val;
}

void solve(){
  int a = input(), b = input(); //just run a bfs from a to b
  //moo("%ld %ld\n", a, b);
  init(dist, 0);
  init(vis, 0);
  queue<int> q;
  q.push(a);
  //moo("%ld %ld\n", a, b);
  while(!q.empty()){
    
    int u = q.front(); q.pop();
    //moo("%d\n", u);
    if(u > pow2(20) || vis[u]) cont;
    if(u == b){
      moo("%ld\n", dist[u]);
      return;
    }
    vis[u] = 1;
    int c = u*2, d = NO(u);
    //moo("%ld %ld %ld\n", u, c, d);
    if(!vis[c] && !dist[c]){ //could not figure this out for the life of me
      orz(dist[c] == dist[u] + 1 || dist[c] == 0);
      dist[c] = dist[u] + 1;
      //vis[c] = 1;
      q.push(c);
    }
    if(!vis[d] && !dist[d]){ //should be both dist[] == 0 AND vis[] == 0
      dist[d] = dist[u] + 1; //fixed after contest. imagine sucking
      //vis[d] = 1;
      q.push(d);
    }
  }
  moo("IMPOSSIBLE\n");
}


signed main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >>T;
  for(int i = 1; i<=T; i++){
    moo("Case #%ld: ", i); solve();
  }
  return 0;
}



