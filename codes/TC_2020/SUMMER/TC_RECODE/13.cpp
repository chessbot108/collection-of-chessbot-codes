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

#define max_v 50
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
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}


bool vis[max_v][max_v];
char board[max_v][max_v];
int n, m;

struct node{
  int x, y, dep;
  node(int a, int b, int c){ x = a, y = b, dep = c; };
};


int bfs(int x, int y){
  queue<node> q;
  q.push(node(x, y, 0));
  int cnt = 0;
  while(!q.empty()){
    node cur = q.front(); q.pop(); //freaking bfs needed. why no recursive floodfill. sad
    if(cur.x < 0 || cur.y < 0 || cur.x >= n || cur.y >= n || vis[cur.x][cur.y] || board[cur.x][cur.y] == '#') cont;
    vis[cur.x][cur.y] = true;
    if(cur.dep == m + 1){ board[cur.x][cur.y] = '$'; cnt++; cont;}
    q.push(node(cur.x + 1, cur.y, cur.dep + 1));
    q.push(node(cur.x, cur.y + 1, cur.dep + 1));
    q.push(node(cur.x - 1, cur.y, cur.dep + 1));
    q.push(node(cur.x, cur.y - 1, cur.dep + 1));

  }
  return cnt;
}

int main(){
	int x, y;
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++){
    scanf("%s", board[i]);
    assert(strlen(board[i]) == n);
    for(int j = 0; j<n; j++) if(board[i][j] == 'Z') x = i, y = j;
  }

  printf("%d\n", bfs(x, y));
  /**
  for(int i = 0; i<n; i++){
    printf("%s\n", board[i]);
  }
  **/
	return 0;
}

