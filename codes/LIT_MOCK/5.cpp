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

#define max_v 110
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


struct node{
  int start, end, x_inc, y_inc;
} nodes[130];


char board[max_v][max_v];
char str[max_v];
bool vis[max_v][max_v];


int main(){
	int n, m, x, y;
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++){
    scanf("%s", board[i]);
    for(int j = 0; j<m; j++) if(board[i][j] == '*') x = i, y = j;    
  }
  
  vis[x][y] = true;
  board[x][y] = '.';
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%s", str);
    if(str[0] == 'N'){
      for(int j = 0; j<m; j++){
        bool X = false;
        for(int i = n - 1; ~i; i--){
          //printf("%d %d, %d \n", i, j, (int)(X));

          if(X) vis[i][j] = true;
          else if(vis[i][j]) X = true, vis[i][j] = false;
          if(board[i][j] == 'X') X = false;
        }
      } 
    } else if (str[0] == 'W'){
      for(int i = 0; i<n; i++){
        bool X = false;
        for(int j = m - 1; ~j; j--){
          if(X) vis[i][j] = true;
          else if(vis[i][j]) X = true, vis[i][j] = false;
          if(board[i][j] == 'X') X = false;
        }
      } 
    }else if(str[0] == 'S'){
      for(int j = 0; j<m; j++){
        bool X = false;
        for(int i = 0; i < n; i++){
          if(X) vis[i][j] = true;
          else if(vis[i][j]) X = true, vis[i][j] = false;
          if(board[i][j] == 'X') X = false;

        }
      } 
    }else{ //East
      for(int i = 0; i<n; i++){
        bool X = false;
        for(int j = 0; j<m; j++){
          //printf("%d %d, %d \n", i, j, (int)(X));
          if(X) vis[i][j] = true;
          else if(vis[i][j]) X = true, vis[i][j] = false;
          if(board[i][j] == 'X') X = false;
        }
      }
    }
    //printf("%d\n", T);
  }
  for(int i = 0; i<n; i++){
    for(int j = 0; j<m; j++){
      printf("%c", (vis[i][j] && board[i][j] != 'X') ? '*' : board[i][j]);
    }
    puts("");
  }
	return 0;
}

