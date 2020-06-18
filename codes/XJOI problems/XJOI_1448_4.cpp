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
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

long long a[max_v], b[max_v];
long long n, k;

bool check(long long mid){
  long long tot = 0ll;
  for(long long i = 0ll; i<n; i++){
    tot += max(b[i] - (long long)(mid*a[i]), 0ll);
  }
  return (tot >= k);
}

long long bin_search(long long l, long long r){
  if(l + 1ll == r) return l;
  long long mid = l + (r - l)/2ll;
 // printf("%lld %lld %lld\n", l, r, mid);
  if(check(mid)){
    return bin_search(mid, r);
  }else{
    return bin_search(l, mid);
  }
}


int main(){
	
  scanf("%lld%lld", &n, &k);
  for(long long i = 0; i<n; i++)
    scanf("%lld", &a[i]);

  for(long long i = 0; i<n; i++)
    scanf("%lld", &b[i]);
  
  long long maxi = -int_max;
  for(long long i = 0; i<n; i++){
    maxi = max(maxi, (b[i] + k) / a[i]);
  }

  printf("%lld\n", bin_search(0ll, (long long)1e9 + 10));


	return 0;
}

