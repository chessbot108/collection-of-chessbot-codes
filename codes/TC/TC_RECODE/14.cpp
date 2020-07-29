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

char str[max_v];
int n;
int dp[max_v];
bool is_prime[(int)(1e8) + 10];

void seive(){
  for(int i = 2; i<=1e8; i++) is_prime[i] = true;
  for(int i = 2; i*i<=1e8; i++){
    if(!is_prime[i]) cont;
    for(int j = i; i*j<=1e8; j++) is_prime[i*j] = false;
  }
}

int to_num(int a, int b){
  int ans = 0;
  for(int i = a; i<b; i++){
    ans = ans*10 + (str[i] - '0');
  }
  return ans;
} 


int main(){
  setIO("14");
  scanf("%s", str);
  n = strlen(str);
  printf("%d\n", n); 
  memset(dp, 0x3f, sizeof(dp));
  seive();
  dp[0] = 0;
  for(int i = 1; i<=n; i++){
    //printf("%d\n", i);
    for(int j = i - 1; ~j && j >= i - 7; j--){
      int cur = to_num(j, i);
      //printf("\t(%d, %d) -> %d, %d\n", i, j, cur, (int)is_prime[cur]);
      if(!is_prime[cur]) cont;
      dp[i] = min(dp[i], dp[j] + 1);
    }
    if(dp[i] == int_max) printf("%d\n", i);
    //printf("dp[%d] = %d\n", i, dp[i]);
  }

  printf("%d\n", dp[n] >= int_max ? -1 : dp[n]);
  

	return 0;
}

