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
vector<string> arr;
multiset<long long> srt;
long long dp[20];
int bit_count[20];

void precomp(){
  for(int i = 1; i<=16; i++){
    bit_count[i] = bit_count[i/2] + i%2;
    printf("bit_count[%d] -> %d\n", i, bit_count[i]);
  }
}




int main(){
  precomp();
	int n, d;
  scanf("%d%d", &n, &d);
  for(int i = 0; i<n; i++){
    string a;
    cin >> a;
    arr.push_back(a);
  }

  for(int i = 1; i<16; i++){
    srt.clear();
    for(int j = 0; j<n; j++){
      long long key = 0ll;
      for(int k = 0; k<4; k++){
        if(pow_2(k)&i) key = key*128 + (long long)arr[j][k];
      }
      srt.insert(key);
    }
    long long ans = 0ll;
    for(long long x : srt){
      ans += (long long)n - (long long)srt.count(x);
    }
    ans >>= 1ll;
    dp[i] = ans;
    printf("%d -> %lld\n", i, dp[i]);
  }
  long long ans = 0ll;
  for(int i = 1; i<16; i++){
    if(bit_count[i] != d) cont;
    ans += dp[(int)((int)15 ^ i)];
    printf("%d %d %lld\n", i, bit_count[i], dp[(int)((int)15 ^ i)]);
  }
  printf("%lld\n", ans);


	return 0;
}

