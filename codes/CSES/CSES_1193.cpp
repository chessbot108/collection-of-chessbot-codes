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
//#include <map>
#include <set>
#include <sstream>
#include <list>
#include <queue>
#include <stack>
//#include <unordered_map>
//#include <unordered_set>
#include <functional>

#define max_v 1100
#define LOGN 50
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << (n))
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define LOG2(n) ((int)(ceil(log2((n)))))

#define  x first
#define y second
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

bool vis[max_v][max_v];
char map[max_v][max_v], delta[max_v][max_v], str[max_v];
pair<int, int> pre[max_v][max_v];
int n, m;

const int row[] = {1, -1, 0, 0};
const int col[] = {0, 0, 1, -1};
const char dir[] = {'L', 'R', 'U', 'D'};


void bfs(int s_X, int s_Y){
  pair<int, int> A = make_pair(-1, -1);
  queue<pair<int, int> > q;
  q.push(make_pair(s_X, s_Y));
  //backwards bfs to make path printing easier
  while(!q.empty()){
    pair<int, int> cur = q.front(); q.pop();
    if(vis[cur.x][cur.y]) cont;
    if(map[cur.x][cur.y] == 'A'){ A = cur; break; }
    vis[cur.x][cur.y] = true;
    for(int i = 0; i<4; i++){
      int X = cur.x + row[i], Y = cur.y + col[i];
      if(X >= 0 && Y >= 0 && X < n && Y < m && !vis[X][Y] && map[X][Y] != '#'){
        pre[X][Y] = cur;
        delta[X][Y] = dir[i];
        q.push(make_pair(X, Y));
      }
    }
  }
  
  if(A == make_pair(-1, -1)){
    printf("NO");
    return ;
  }else{
    int N = 0;

    printf("YES\n");
    while(A != make_pair(s_X, s_Y)){
      str[N++] = delta[A.x][A.y];
      //printf("%c", delta[A.x][A.y]);
      A = pre[A.x][A.y];
    }
    str[N] = 0;
    std::reverse(str, str + N);
    printf("%d\n%s", N, str);
  }


}

int main(){
  scanf("%d%d", &n, &m);
  int X, Y;
  for(int i = 0; i<n; i++){
    scanf("%s", map[i]);
    assert(strlen(map[i]) == m);
    for(int j = 0; j<m; j++){
      if(map[i][j] == 'B') X = i, Y = j;
    }
  }
  bfs(X, Y);
	return 0;
}

