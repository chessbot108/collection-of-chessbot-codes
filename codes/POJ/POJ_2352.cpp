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
#include <utility>
//#include <unordered_map>
//#include <unordered_set>
#include <functional>
#include <iterator>

#define max_v 40000
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

vector<pair<int, int>> points;
int ans[max_v], BIT[max_v * 2];

int S(int k){
  if(k <= 0) return 0;
  return BIT[k] + S(k - lsb(k));
}

void U(int k){
  if(k >= max_v) return ;
  BIT[k]++;
  U(k + lsb(k));
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 0; i<n; i++){
    int x, y;
    scanf("%d%d", &x, &y);
    points.push_back(make_pair(++x, ++y));
  }

  sort(points.begin(), points.end());

  for(int i = 0; i<n; i++){
    int t = S(points[i].second);
    ans[t]++;
    U(points[i].second);
  }

  for(int i = 0; i<n; i++){
    printf("%d\n", ans[i]);
  }
  
	return 0;
}

