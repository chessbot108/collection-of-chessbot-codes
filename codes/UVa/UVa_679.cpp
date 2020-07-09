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


int solve(int D, int I){
  if(!D || !I) return 0;
  if(D&1) return pow_2(I - 1) + solve(D >> 1, I - 1);
  else return solve(D >> 1, I - 1);
}


int main(){
  int l;
  scanf("%d", &l);
  while(l--){
    int D, I;
    scanf("%d%d", &D, &I);
    I--;
    printf("%d\n", pow_2(D - 1) + solve(I, D - 1));
  }
  
  scanf("%d", &l);
  assert(!(~l));

	return 0;
}

