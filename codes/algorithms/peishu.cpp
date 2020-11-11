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

int gcd(int a, int b){
  a = abs(a), b = abs(b);
  if(a < b) swap(a, b);
  if(b == 0) return a;
  return gcd(b, a%b);
}




int main(){
  int n, ans;
  scanf("%d%d", &n, &ans); n--;
  while(n--){
    int a;
    scanf("%d", &a);
    ans = gcd(a, ans);
  }
  printf("%d\n", ans);
	return 0;
}

