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

#define max_v 1100000
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

const long long mod = (long long)(1e9 + 7);
const long long inv_2 = (long long)(1e9 + 8)/(2ll);

long long inv[max_v], fac[max_v/10], cnt[max_v/10], sigma = 1ll;
int n;

long long bin_pow(long long a, long long b){
  b %= (mod - 1); //fermat's little theorem to force bin_pow to run in O(log mod)
  long long ans = 1ll;
  for(long long i = 1; i<=b; i <<= 1){
    if(i&b) (ans *= a) %= mod;
    (a *= a) %= mod;
  }
  return ans;
}

long long tri(long long k){ //returns the "triangle number" of k
  long long temp = (k * (k + 1ll)) % mod;
  return (temp * inv_2) % mod;
}

long long div(long long a, long long b){//divide a by b mod 1e9 + 7
  return ((a * inv[b]) % mod);
}


void precomp(){
  inv[1] = 1ll;
  for(long long i = 2ll; i<= (long long)(1e6 + 10); i++){
    inv[i] = ((long long)(mod - (mod/i)) * inv[mod % i]) % mod;
  }
  /**
  for(int i = 1; i<=1e6; i++){
    printf("%lld and %lld\n", inv[i], bin_pow((long long)i, mod - 2));
  }
  **/
}


int main(){
  precomp();
	scanf("%d", &n);
  
  for(int i = 0; i<n; i++){
    scanf("%lld%lld", &fac[i], &cnt[i]);
    (sigma *= cnt[i]) %= mod;
  }



  
  return 0;
}

