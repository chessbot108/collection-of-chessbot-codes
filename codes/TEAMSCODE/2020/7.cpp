//code by me
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

int arr[110][110];
int dp[110][110];
int col[] = {0, 0, -1, 1};
int row[] = {1, -1, 0, 0};
vector<pair<int, pair<int, int>>> points;


int main(){
  int R, C;
  memset(dp, 0x8f, sizeof(dp));
  memset(arr, 0x3f, sizeof(arr));
  scanf("%d%d", &R, &C);
  for(int i = 1; i<=R; i++){
    for(int j = 1; j<=C; j++){
      scanf("%d", &arr[i][j]);
      points.push_back(make_pair(arr[i][j], make_pair(i, j)));
    }
  }

  sort(points.begin(), points.end());
  int ans = 0;
  //dp[points[0].second.first][points[0].second.second] = 1;
  for(auto p : points){
    int x= p.second.first, y = p.second.second;
    //printf("%d %d %d\n", p.first, x, y);
    for(int i = 0; i<4; i++){
      if(arr[x][y] >arr[x + col[i]][y + row[i]])
        dp[x][y] = max(dp[x][y], dp[x + col[i]][y + row[i]]); 
    }
    dp[x][y] = max(1, dp[x][y] + 1);;
    ans = max(ans, dp[x][y]);
  }
  printf("%d\n", ans);
	return 0;
}

