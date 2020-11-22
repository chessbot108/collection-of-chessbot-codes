//debugging attemps for #14, did not end up helping :sobasobabbob:

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
#define int_max 0x3f3f3f3f
#define cont continue
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


int main(){
  srand(time(0));
  int n;
  scanf("%d", &n);
  for(int i = 2; i<=n; i++){
    int r = rand()%(i - 1) + 1;
    printf("%d %d\n", i, r);
  }
  for(int i = 1; i<=n; i++){
    int r = rand() %1000 +1;
    printf("%d 1\n", r);
  }
	return 0;
}

