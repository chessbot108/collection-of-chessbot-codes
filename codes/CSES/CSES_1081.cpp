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

#define max_v 1100000
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

int buckets[max_v];
int max_div[max_v], fact[max_v];

int main(){
  int n, ans = 1, a;
  scanf("%d", &n);
  while(n--){
    scanf("%d", &a);
    buckets[a]++;
  }

  for(int i = 1; i<=1e6; i++){
    int cnt = 0;
    for(int j = 1; j * i <= 1e6; j++){
      cnt += buckets[i * j];
    }
    if(cnt >= 2) ans = i;
  } 
  printf("%d\n", ans);
    
	return 0;
}

