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
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))

#define moo printf
#define oom scanf
#define mool puts(""); 
#define loom getline
const ll mod = 1e9 + 7;
const int MX = 3e2 +10, int_max = 0x3f3f3f3f;
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

const int dx[] = {0, 0, -1, 1}; 
const int dy[] = {-1, 1, 0, 0};

struct node{
  int x, y, w;
  node(){}
  node(int a, int b, int c){x = a, y =b, w= c;}
  bool operator < (const node& b) const{
    return w < b.w; //remember i want max this time
  }
};

int arr[MX][MX], vis[MX][MX];

priority_queue<node> pq;
ll solve(){
  int n, m; cin >> n >> m;
  init(arr, 0);
  init(vis, 0);
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m; j++){
      cin >> arr[i][j];
      pq.push(node(i, j, arr[i][j]));
    }
  }
  ll ans = 0ll; 
  while(!pq.empty()){
    node cur= pq.top(); pq.pop();
    int x = cur.x, y = cur.y;
    //moo("cur: %d %d %d\n", x, y, cur.w);
    if(vis[x][y]) cont;
    vis[x][y] = 1;
    ans += (ll)(cur.w - arr[x][y]);
    arr[x][y] = cur.w;
    for(int i = 0; i<4; i++){
      int cx = x + dx[i], cy = y + dy[i];
      if(cx <= 0 || cy <= 0 || cx > n || cy > m || abs(arr[cx][cy] - cur.w) <= 1) cont;
      //moo("\tcandidate nodes: %d %d %d\n", cx, cy, cur.w-1);
      assert(arr[x][y] > arr[cx][cy]);
      pq.push(node(cx, cy, cur.w-1));
    }
  }

  /** 
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m; j++){
      moo("%3d ", arr[i][j]);
    } mool;
  }
  **/
  return ans;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  for(int i = 1; i<=T; i++){
    moo("Case #%d: %lld\n", i, solve());
  }
	return 0;
}

