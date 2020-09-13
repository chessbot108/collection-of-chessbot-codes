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

const int mod = 1e9 + 7;

int bin_pow(int a, int b){
  long long ans = 1, ind = (long long)a;
  for(int i = 0; pow_2(i) <= b; i++){
    if(b & pow_2(i)){
      (ans *= ind) %= mod;
    }
    (ind *= ind) %= mod;
  }
  return ans;
} 


int main(){
  int n;
  scanf("%d", &n);
  while(n--){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", bin_pow(a, b));
  }
	return 0;
}

