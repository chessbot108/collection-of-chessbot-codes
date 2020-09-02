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
#define x first
#define y second
using namespace std;



long long graph[max_v][max_v];
vector<pair<int, int> > points;
bool endpoint[max_v], vis[max_v];
long long DP[max_v];

long long dp(int i){
  if(points[i].x == 0 && points[i].y == 0) return 0ll;
  if(vis[i]) return DP[i];
  vis[i] = true;
  //printf("%d -> (%d, %d)\n", i, points[i].first, points[i].second);
  for(int j = 0; j < points.size(); j++){
    if(graph[j][i] <= (long long)2e9){ //LONG LONG MAX
      ////printf("from (%d, %d) -> (%d, %d) is %11lld\n", points[j].x, points[j].y, points[i].x, points[i].y, graph[j][i]);
      DP[i] = min(dp(j) + graph[j][i], DP[i]);
    }
  }
  //printf("dist from origin to (%d %d) is %11lld", points[i].x, points[i].y, DP[i]);
  return DP[i];
}

int main(){
  int n, p;
  scanf("%d%d", &n, &p);

  memset(graph, 0x3f, sizeof(graph));
  memset(DP, 0x3f, sizeof(DP));
  
  for(int i = 0; i<p; i++){
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    points.push_back(make_pair(a, b));
    points.push_back(make_pair(c, d));
    endpoint[i*2 + 1] = true;
    graph[i*2][i*2 + 1] = 0;
  }
  points.push_back(make_pair(0, 0));
  points.push_back(make_pair(n, n));
   
  for(int i = 0; i<points.size(); i++){
    for(int j = 0; j<points.size(); j++){
      if(i != j && points[i].x <= points[j].x && points[i].y <= points[j].y && !endpoint[j]){ // i != j, i is the to left and further down than j, j is not an endpoint
        graph[i][j] = (long long)min(graph[i][j], (long long)abs(points[i].x - points[j].x) + abs(points[i].second - points[j].second)); // in case it was a springboard
      }
    }
  }
  /**
  for(int i = 0; i<points.size(); i++){
    printf("point %d is (%d, %d)\n", i, points[i].first, points[i].second);
    for(int j = 0; j<points.size(); j++){
      printf("\tdist to (%d, %d) is %11lld\n", points[j].first, points[j].second, graph[i][j]);
    }
  }
  **/
  printf("%lld\n", dp(points.size() - 1));
	return 0;
}

