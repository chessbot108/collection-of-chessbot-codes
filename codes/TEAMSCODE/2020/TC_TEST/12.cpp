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
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int dp[max_v][max_v];
int arr[max_v][max_v];


int main(){
	int n, C;
  cin >> n >> C;
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n; j++){
      cin >> arr[i][j];
    } 
  }
  arr[1][1] = C; 
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n; j++){
      if(i > 1) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      if(j > 1) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
      dp[i][j] += arr[i][j];
    }
  }
  
  cout << dp[n][n];
    
	return 0;
}

