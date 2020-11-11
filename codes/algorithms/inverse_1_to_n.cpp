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

#define max_v 3100000
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

int inv[max_v];


void comp(int n, int p){
  inv[1] = 1;
  for(int i = 2; i<=n+10; i++){
    inv[i] = ((long long)(p - (p/i)) * inv[p % i]) % p;
  }
  for(int i = 1; i<=n; i++){
    printf("%d\n", inv[i]);
  }

}


int main(){
	int n, p;
  scanf("%d%d", &n, &p);
  comp(n, p);
	return 0;
}

