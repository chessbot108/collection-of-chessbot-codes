#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <list>
#include <queue>
#include <stack>
//#include <unordered_map>
//#include <unordered_set>
#include <functional>

#define max_v 1100
#define int_max 0x3f3f3f3f
#define cont continue

using namespace std;
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};
struct node{
  int x, y, dist;
  node(){}
  node(int a, int b, int c){x = a, y = b, dist = c;}
  const bool operator < (const node& b) const{
    return dist > b.dist;
  }
};

vector<pair<int, int>> S;
vector<pair<int, int>> rock, temp;

priority_queue<node> pq;
queue<node> q;
int dist[max_v][max_v], vis[max_v][max_v], arr[max_v][max_v], sen[max_v][max_v], ans[max_v][max_v]; //sensitivty radius of each node
int n, D;
char str[max_v];

void precomp_sen(){
  for(auto p : rock){
    q.push(node(p.first, p.second, 0));
  }

  while(!q.empty()){  
    auto cur = q.front(); q.pop();
    int x = cur.x, y = cur.y, d = cur.dist;
    //printf("%d %d %d\n", x, y, d);
    if(x <= 0 || x > n || y <= 0 || y > n || vis[x][y]) cont;
    sen[x][y] = d;
    vis[x][y] = 1;
    q.push(node(x + 1, y, d + 1));
    q.push(node(x - 1, y, d + 1));
    q.push(node(x, y - 1, d + 1));
    q.push(node(x, y + 1, d + 1));
  }
  memset(vis, 0, sizeof(vis));
}

void expand_S(int s, int X, int Y){
  //printf("expanding S with s as %d\n", s);
  q = queue<node>();
  q.push(node(X, Y, 0));
  for(auto p : S){
    q.push(node(p.first, p.second, 0));
  }
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    int x = cur.x, y = cur.y, d = cur.dist;
    //printf("\t%d %d %d\n", x, y, d);
    if(x <= 0 || x > n || y <= 0 || y > n || vis[x][y] || arr[x][y] == -1) cont;
    if(d == s + 1) cont;
    ans[x][y] = 1;
    if(!ans[x + 1][y]) q.push(node(x + 1, y, d + 1)); //copy and past magic
    if(!ans[x - 1][y]) q.push(node(x - 1, y, d + 1));
    if(!ans[x][y - 1]) q.push(node(x, y - 1, d + 1));
    if(!ans[x][y + 1]) q.push(node(x, y + 1, d + 1));

  }
}


void find_S(int s){ //s is for sensitivity and S is for starting points
  printf("s == %d\n", s);
  memset(dist, 0x3f, sizeof(dist));
  memset(vis, 0, sizeof(vis));
  for(auto p : S){
    pq.push(node(p.first, p.second, 0));
    dist[p.first][p.second] = 0;
    //printf("%d %d\n", p.first, p.second);
    ans[p.first][p.second] = 1;
  } 
  //puts("");
  
  S.clear();
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    int x = cur.x, y = cur.y, d = cur.dist;
    if(vis[x][y] || sen[x][y] < s){ cont; }
    if(sen[x][y] == s){ expand_S(x, y, s); cont; }
    if(d == D){ S.push_back(make_pair(x, y)); cont; }
    vis[x][y] = true;
    for(int i = 0; i<4; i++){
      int X = x + row[i], Y = y + col[i];
      if(X <= 0 || X > n || Y <= 0 || Y > n || vis[X][Y] || arr[X][Y] == -1 || dist[X][Y] <= d + 1) cont;
      dist[X][Y] = d + 1;
      ans[X][Y] = 1;
      pq.push(node(X, Y, d + 1)); //dijkstra on steriods.
    }
  }
  //for(auto p : S){
    //printf("%d %d\n", p.first, p.second);
  //}
  for(auto p : S)
    expand_S(p.first, p.second, s);
}





int main(){
  scanf("%d%d", &n, &D);
  for(int i = 1; i<=n; i++){
    scanf("%s", str + 1);
    assert(strlen(str + 1) == n);
    for(int j = 1; j<=n; j++){
      if(str[j] == '#'){
        rock.push_back(make_pair(i, j));
        arr[i][j] = -1;
      }else if(str[j] == 'S'){
        S.push_back(make_pair(i, j));
        arr[i][j] = 1;
      }else{
        arr[i][j] = 0;
      }
    }
  }
  precomp_sen();
  for(int s = 0; !S.empty(); s++){
    find_S(s);
  }
  
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n; j++){
      printf("%d ", sen[i][j]);
    }
    puts("");
  }
  
  int res = 0;
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n; j++){
      res += ans[i][j];
      printf("%d ", ans[i][j]);
    }
    puts("");
  }
  printf("%d\n", res);
	return 0;
}

