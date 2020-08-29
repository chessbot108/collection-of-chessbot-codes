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

//TLE solution all the way

int l[20], r[20];
bool vis[20];
int n, mod = (int)1e9 + 7;

int eval(int B){
  memset(vis, false, sizeof(vis));
  
  

  return cnt;
}


int main(){
	scanf("%d", &n);
  for(int i = 0; i<n; i++){
    scanf("%d%d", &l[i], &r[i]);
  }
  int ans = 0;
  for(int i = 1; i<pow_2(n); i++){
    ans += eval(i);
  }
  printf("%d\n", ans);

	return 0;
}

