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

#define max_v 11000
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
//at leat 1 free problem
int dp[max_v];
int arr[max_v];
int n, k;

int main(){
	scanf("%d%d", &n, &k);
  for(int i = 1; i<=n; i++){
    scanf("%d", &arr[i]);
  }
  dp[1] = 0;
  for(int i = 2; i<=n + 1; i++){
    int maxi = 0;
    //printf("%d\n", i);
    for(int j = i - 1; j >= 1 && (i - j) <= k; j--){
      maxi = max(arr[j], maxi);
      //printf("\t%d, %d %d\n", j, arr[j], maxi);
      dp[i] = max(dp[i], dp[j] + (i - j) * maxi);
    }
    //printf("dp[%d] == %d\n", i, dp[i]);
  }
  printf("%d\n", dp[n + 1]); //dude i don't even
	return 0;
}

