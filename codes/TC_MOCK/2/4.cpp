//code by weiming

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

bool p[max_v];

int main(){
	for(int i = 2; i<=1e5; i++){
    for(int j = 2; i * j <= 1e5; j++){
      p[i*j] = true;
    }
  }
  p[1] = true;
  int T;
  scanf("%d", &T);
  while(T--){
    int a;
    scanf("%d", &a);
    cout << ((p[a]) ? "No" : "Yes") << endl;
  }

  return 0;
}

