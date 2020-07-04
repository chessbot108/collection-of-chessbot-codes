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

#define max_v 51000
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

const int coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
long long dp[max_v]; //dp[i] is the amount of ways to make i value with the coins



int main(){
	
  dp[0] = 1ll;

  for(int j = 0; j<11; j++){
    for(int i = 0; i<=30000; i++){
      dp[i + coins[j]] += dp[i];
    }
  }
  
  double n;
  while(scanf("%lf", &n)){
    int t = (n * 10.0) * 10.0; //slightly tilted. decimal conversion is dumb
    if(!t) break;
    printf("%6.2lf%17lld\n", n, dp[t]);
  }

	return 0;
}

