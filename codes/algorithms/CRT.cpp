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

long long a[max_v], b[max_v];
long long M = 1, x;





int main(){
	int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    scanf("%lld %lld", &b[i], &a[i]);
    M *= b[i];
  }
  //printf("%lld\n", M); 
  for(int i = 0; i<n; i++){
    long long inv;
    for(int j = 1; j<=b[i]; j++){
      if(((M/b[i]) * (long long)j) % b[i] == 1ll){inv = j; break; }
    }
    //printf("for eq %d\nMi -> %lld\nyi -> %lld\nai -> %d\n", i + 1, M/b[i], inv, a[i]);
    x = x + (((inv * M/b[i]) % M)*a[i] % M);
    x %= M;
    
  }
  printf("%lld\n", x);

	return 0;
}

