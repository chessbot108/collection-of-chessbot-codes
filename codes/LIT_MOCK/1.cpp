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


char b[max_v];
char a[max_v];

int main(){
  scanf("%s%s", a, b);  
  int n = strlen(a), m = strlen(b);
  long long A = 0ll, B = 0ll;
  if(n > m){ printf("%s\n", b); return 0;}
  for(int i = 0; i<n; i++){
    A = (long long)((A*10) + (a[i] - '0'));
    B = (long long)((B*10) + (b[i] - '0'));
  }
  
  int i = n;
  
  //if(A > B){
    //B = (long long)(B*10) + (b[i] - '0'); //append a digit is B starts too small
    //i++;
  //}
  //printf("%d %d\n", A, B);
  while(i < m){
    B = (long long)((B%A)*10) + (b[i] - '0');
    i++;
  }
  

  printf("%lld\n", (B%A) ? B%A : B);


	return 0;
}

