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

vector<pair<long long, long long>> intervals;

long long n, m;

bool works(long long D){
  long long cur = 0ll, cnt = 0ll;
  for(int i = 0; i<m; i++){
    if(cur > intervals[i].second) cont;
    cur = max(cur, intervals[i].first);
    long long temp = (intervals[i].second - cur) / D +1ll;
    cnt += temp;
    cur += D * temp;
  }
  return cnt >= n;
}

long long bin_search(long long l, long long r){
  long long mid = (l + r) / 2;
  if(r - l < 10){
    for(long long i = l; i<=r; i++){
      if(!works(i)) return i - 1;
    }
  }else if(works(mid)){
    return bin_search(mid, r);
  }else{
    return bin_search(l, mid);
  }
}


int main(){
	scanf("%lld%lld", &n, &m);
  for(int i = 0; i<(int)m; i++){
    long long a, b;
    scanf("%lld%lld", &a, &b);
    intervals.push_back(make_pair(a, b));
  }
  sort(intervals.begin(), intervals.end());
  printf("%lld\n", bin_search(1ll, (long long)1e18));
	return 0;
}

