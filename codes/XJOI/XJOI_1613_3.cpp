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
#include <unordered_set>
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

queue<pair<long long, long long>> q; 
long long  n;
long long mod;
long long primes[100];
int size = 0;
unordered_set<long long> vis;

void comp(){
  for(int i = 2; i<=100; i++){
    primes[size++] = i;
    for(int j = 2; j<i; j++){
      if(i % j == 0){size--; break;}
    }
  }
  /**
  for(int i = 0; i<size; i++){
    printf("%d\n", primes[i]);
  }
  **/
}



int main(){
  comp();
  scanf("%lld%lld", &n, &mod);
  
  long long ans = 0ll;
  q.push(make_pair(1ll, 0ll));
  while(!q.empty()){
    auto p = q.front(); q.pop();
    if(p.second > n || vis.count(p.first)) cont;
    //printf("%d %d\n", p.first, p.second);
    ans = (ans + p.first) % mod;
    vis.insert(p.first);
    for(int i = 0; i < size; i++){
      q.push(make_pair((primes[i] * (p.first%mod))%mod, p.second + primes[i]));
    }
  }
  printf("%lld\n", ans);
	return 0;
}

