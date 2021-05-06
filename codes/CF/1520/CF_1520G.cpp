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
const int MX = 2e3 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int row[] = {1, -1, 0, 0};
const int col[] = {0, 0, 1, -1};

struct node{
  int x, y; ll w;
  node(){}
  node(int a, int b, ll c){ x = a, y = b, w = c; }
};

queue<node> q;

ll dist[MX][MX], arr[MX][MX];
int n, m; ll w, D = (ll)(1e17);
bool vis[MX][MX];


ll bfs(int sx, int sy){
  init(dist, 0);
  init(vis, 0);
  q = queue<node>(); 
  q.push(node(sx, sy, 0ll));
 
  ll ans = 1e17;

  while(!q.empty()){
    node cur = q.front(); q.pop();
    int x = cur.x, y = cur.y; ll d = cur.w;
    if(x < 1 || y < 1 || x > n || y > m || vis[x][y] || arr[x][y] == -1) cont;
    if(sx == 1 && sy == 1 && x == n && y == m){
      D = d;//hahahah
      break;
    }
    if(arr[x][y] >= 1){
      ans = min(ans, arr[x][y] + d);
    }
    vis[x][y] = 1;
    dist[x][y] = d;
    for(int i = 0; i<4; i++){
      int dx = x + col[i], dy = y + row[i];
      q.push(node(dx, dy, d + w));
    }
    
  }
  if(ans == (ll)1e17 && D == (ll)(1e17)){
    moo("-1\n"); exit(0);
  }
  orz(ans >= 0);
  return ans;
}




int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m >> w;
  for(int i = 1; i<=n; i++) for(int j = 1; j<=m; j++) cin >> arr[i][j];
  ll st = bfs(1, 1);
  ll en = bfs(n, m);
  //moo("%lld %lld, %lld\n", st, en, D);
  moo("%lld\n", min(st + en, D));
  return 0;
}


