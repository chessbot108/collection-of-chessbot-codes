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

const long long mod = (long long)1e9 + 7;

long long F(long long a, long long b){// returns sym of all integers [a, b]
  if(a > b) swap(a, b);
  long long A = (b + 1ll - a) % mod;
  long long B = ((a%mod) * A) % mod;
  long long C = ((b - a) % 2ll) ? b - a : (b - a) / 2ll;
  long long D = ((b + 1ll - a) % 2ll) ? b + 1ll - a : (b + 1ll- a) / 2ll;
  C %= mod;
  D %= mod;
  return ((C * D) % mod + B) % mod;
}


int main(){
  long long n, tot = 0ll;
  scanf("%lld", &n);
  for(long long i = 1ll; n/i>(long long)floor(sqrt(n)); i += 1ll){
    (tot += F(n/i, 1ll + (n/(i + 1ll))) * (i%mod)) %= mod;
    //printf("%lld %lld -> %lld\n", n/i, 1ll + (n/(i + 1ll)), F(n/i,  1ll + (n/(i + 1ll) * i)));
  }
  //printf("%lld\n", tot);
  //for(int i = 0; i<n; i++){
    //long long a, b;
    //scanf("%lld%lld", &a, &b);
    //printf("%lld\n", F(a, b));
  //}
  for(long long i = 1ll; i<=(long long)floor(sqrt(n)); i += 1ll){
    (tot += (i%mod) * (n/i)) %= mod;
  }
  printf("%lld\n", tot);
	return 0;
}

