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
//this problem is also known as "haircut" for usaco gold us open 2020

list<int> arr[max_v]; // the indeces for each value
int BIT[max_v], n;
long long ans[max_v]; //1e5^2 > 2e9

int S(int k){
  return (k) ? BIT[k] + S(k - lsb(k)) : 0; //the final form of recursive BIT. alby, tell me iterative looks better.
}

void U(int k){ //always by 1
  if(k > n) return ;
  BIT[k]++; U(k + lsb(k));
}

int main(){
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    int a;
    scanf("%d", &a);
    arr[a].push_front(i + 1); //1 based to avoid fenceposts
  }


  for(int i = n; ~i; i--){
    for(int x : arr[i]){
      //printf("%d %d\n", i, x);
      ans[i] += S(x);
      U(x);
    }
  }
  
  long long total = 0; //overflow
  
  for(int i = 0; i<n; i++){
    printf("%lld\n", total);
    total += (long long)ans[i];
  }
	
  return 0;
}


