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


int pre[max_v][max_v];
char str[max_v][max_v];
int n, q;

int main(){
	scanf("%d%d", &n, &q);
  for(int i = 0; i<n; i++){
    scanf("%s", str[i]);
    for(int j = 0; j<n; j++){
      pre[i + 1][j + 1] = (str[i][j] == '*') ? 1 : 0;
      pre[i + 1][j + 1] += pre[i + 1][j] + pre[i][j + 1] - pre[i][j];
    }
  }
  while(q--){
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    a--, b--;
    printf("%d\n", pre[a][b] + pre[c][d] - (pre[a][d] + pre[c][b]));
  }
	return 0;
}

