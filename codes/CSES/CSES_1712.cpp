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
//i'm wondering if doing binpow on a^b, then doing (a^b %mod)^c would work
//aight i asked some geniousities for help
//and i got FML (fermats little theorem)
//so basically a^b % c == a ^ (b % c - 1) % c
//which makes the problem doable with the exponent under 1e9 + 6
//so it's good

int bin_pow(int a, int b, int mod){
  long long ans = 1, ind = (long long) a;
  for(int i = 0; pow_2(i) <= b; i++){
    if(b & pow_2(i)){
      (ans *= ind) %= mod;
    }
    (ind *= ind) %= mod;
  }
  return ans;
}


int main(){
	int n;
  scanf("%d", &n);
  while(n--){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", bin_pow(a, bin_pow(b, c, 1e9 + 6), 1e9 + 7));
  }
	return 0;
}

