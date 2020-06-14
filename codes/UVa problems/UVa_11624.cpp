#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <queue>
#include <cassert>

#define max_v 260
using namespace std;

struct node{
  int x, y, key;
  node(int a, int b, int c){
    x = a, y = b, key = c;
  }
  node(){}
};
const int row[] = {0, 0, -1, 1};

const int col[] = {-1, 1, 0, 0};

int j_dist[1100][1100], f_dist[1100][1100];
char arr[1100][1100];
bool vis[1100][1100]; 
int n, m;
queue<node> q;

void bfs(int dist[1100][1100]){
 memset(vis, 0, sizeof(vis));
 while(!q.empty()){
  node top = q.front(); q.pop();
  int x = top.x, y = top.y, key = top.key;
  if(x < 0 || y < 0 || x >= n || y >= m || arr[x][y] == '#' || vis[x][y]) continue;
  dist[x][y] = key;
  vis[x][y] = true;
  for(int i = 0; i<4; i++){
    int X = x + row[i], Y = y + col[i];
    q.push(node(X, Y, key + 1));
  }
 }
  
}


int main(){
  freopen("a.in", "r", stdin);
  freopen("a.out", "w+", stdout);
  int T;
  scanf("%d", &T);

  while(T--){
    scanf("%d%d", &n, &m);
    //memset(arr, 0, sizeof(arr));
    memset(j_dist, 0x3f, sizeof(j_dist));
    memset(f_dist, 0x3f, sizeof(f_dist));

    for(int i = 0; i<n; i++){
      scanf("%s", arr[i]);
      assert((int)strlen(arr[i]) == m);
    }

    node J;
    for(int i = 0; i<n; i++){
      for(int j = 0; j<m; j++){
        if(arr[i][j] == 'J'){
          J = node(i, j, 0);
        }else if(arr[i][j] == 'F'){
          q.push(node(i, j, 0));
        }
      }
    }
    
    bfs(f_dist);
    q.push(J);
    bfs(j_dist);

    int sol = 0x3f3f3f3f;
    for(int i = 0; i<n; i++){
      if(j_dist[i][0] < f_dist[i][0])
          sol = min(sol, j_dist[i][0]);
      if(j_dist[i][m-1] < f_dist[i][m-1])
          sol = min(sol, j_dist[i][m-1]);
    }

    for(int j = 0; j<m; j++){
      if(j_dist[0][j] < f_dist[0][j])
        sol = min(sol, j_dist[0][j]);
      if(j_dist[n-1][j] < f_dist[n-1][j])
        sol = min(sol, j_dist[n-1][j]);
    }

    if(sol == 0x3f3f3f3f){
      puts("IMPOSSIBLE");
    }else{
      printf("%d\n", sol + 1);
    }

        
  }



  return 0;
}
