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

#define max_v 110000
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


char arr[max_v];
int dp[max_v];

set<int> primes;
bool is_prime(int v){
  if(v == 1 && v == 0) return false;
  if(primes.count(v)) return true;
  for(int i = 2; i <= sqrt(v) + 1; i++){
    if(v%i == 0) return false;
  }
  primes.insert(v);
  return true;
}


int main(){
	scanf("%s", arr + 1);
  int n = strlen(arr + 1);
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  for(int i = 1; i<=n; i++){
    int t = arr[i] - '0';
    //printf("%d\n", i);
    for(int j = i; j >= max(i - 6, 1); j--){
      //printf("\tfor %d, %d, %d, %d\n", j, t, (int)is_prime(t), dp[j - 1]);
      if(is_prime(t)) dp[i] = min(dp[j - 1] + 1, dp[i]);
      t += (arr[j - 1] - '0') * (int)pow(10, i - j + 1);
    }
    //printf("%d \n", dp[i]);
  }
  printf("%d\n", dp[n] >= int_max ? -1 : dp[n]);
	return 0;
}

