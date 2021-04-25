//code my me

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
const int MX = 1e3 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
  freopen((file_name+".in").c_str(), "r", stdin);
  freopen((file_name+".out").c_str(), "w+", stdout);
}

const int row[] = {0, 0, -1, 1};
const int col[] = {1, -1, 0, 0};

int vis[MX][MX], arr[MX][MX];
ll dp[MX][MX];

int n, m;

struct node{
  int x, y, d;
  node(){}
  node(int a, int b, int c){ x = a, y = b, d = c; }
  bool wo(){
    return (x) && (y) && (x <= n) && (y <= m) && (arr[x][y] == 0);
  }
  bool operator < (const node& b) const{
    return d < b.d;
  }
};

queue<node> q;
vector<node> vec;

void bfs(){
  q.push(node(1, 1, 1));
  while(!q.empty()){
    node c = q.front(); q.pop();
    int x = c.x, y = c.y, d = c.d;
    if(vis[x][y]) cont;
    vis[x][y] = d;
    if(x == n && y == m) break;
    //moo("%d %d %d\n", x, y, d);
    for(int i = 0; i<4; i++){
      int a = x + row[i], b = y + col[i];
      if(vis[a][b]) cont;
      node temp = node(a, b, d + 1);
      if(temp.wo()) q.push(temp);
    }
  }
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m; j++){
      cin >> arr[i][j];
    }
  }
  bfs();
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m; j++){
      if(vis[i][j]) vec.pb(node(i, j, vis[i][j]));
    }
  }
  sort(vec.begin(), vec.end());
  dp[1][1] = 1ll;
  for(int i = 0; i<vec.size(); i++){
    //moo("%d %d %d\n", vec[i].x, vec[i].y, vec[i].d);
    for(int j = 0; j<4; j++){
      if(vis[vec[i].x + row[j]][vec[i].y + col[j]] == vis[vec[i].x][vec[i].y] - 1) dp[vec[i].x][vec[i].y] = add(dp[vec[i].x][vec[i].y], dp[vec[i].x + row[j]][vec[i].y + col[j]]); 
    }
  }
  moo("%lld\n", dp[n][m]);
  return 0;
}


