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
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) | 1)
#define RC(n) (((n) << 1) + 2)
#define LOG2(n) ((int)ceil(log2((n))))
using namespace std;
const int MOD = 10007;
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int add[max_v], mult[max_v], set_tag[max_v];
long long sum1[max_v], sum2[max_v], sum3[max_v];
bool marked[max_v];

void tag(int k, int len, int a, int b, int c){
  //a is set
  //b is add
  //c is mult

  if (marked[k]) { // a != -1
      set_tag[k] = a;
      mult[k] = b;
      add[k] = c;
      int p = (a * b + c) % MOD;
      sum1[k] = p * len % MOD;
      sum2[k] = p * sum1[k] % MOD;
      sum3[k] = p * sum2[k] % MOD;
  } else {
      (mult[k] *= b) %= MOD;
      ((add[k] *= b) += c) %= MOD;
      (sum1[k] *= b) %= MOD;
      (sum2[k] *= b * b % MOD) %= MOD;
      (sum3[k] *= b * b % MOD * b % MOD) %= MOD;
      int c2 = c * c % MOD, c3 = c * c2 % MOD;
      (sum3[k] += c * sum2[k] % MOD * 3 + c2 * sum1[k] % MOD * 3 + c3 * len % MOD) %= MOD;
      (sum2[k] += c * sum1[k] % MOD * 2 + c2 * len % MOD) %= MOD;
      (sum1[k] += c * len % MOD) %= MOD;
  }
  
}


int main(){
	
	return 0;
}

