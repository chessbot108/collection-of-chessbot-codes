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

#define max_v 210000
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

long long BIT[max_v], arr[max_v];
int n, m;

void U(int k, long long val){ for(; k<=n; k += lsb(k)) BIT[k] += val; }
long long S(int k){ return (!k) ? 0ll : BIT[k] + S(k - lsb(k)); }

int main(){
	scanf("%d%d", &n, &m);
  for(int i = 1; i<=n; i++){
    scanf("%lld", &arr[i]);
    U(i, arr[i] - arr[i - 1]);
  }
  while(m--){
    int op, a, b, val;
    scanf("%d", &op);
    if(op - 1){
      scanf("%d", &a);
      printf("%lld\n", S(a));
    }else{
      scanf("%d%d%d", &a, &b, &val);
      U(a, (long long)val);
      U(b + 1, (long long)-val);
    }
  }
	return 0;
}

