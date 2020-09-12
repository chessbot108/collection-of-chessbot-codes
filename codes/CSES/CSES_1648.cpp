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

long long S(int k){ return (!k) ? 0ll : BIT[k] + S(k - lsb(k)); }
void U(int k, long long val){ for(; k<=n; k += lsb(k)) BIT[k] += val; }


int main(){
	scanf("%d%d", &n, &m);
  for(int i = 1; i<=n; i++){
    scanf("%lld", &arr[i]);
    U(i, arr[i]);
  }
  while(m--){
    int op, a, b;
    scanf("%d%d%d", &op, &a, &b);
    if(op - 1){
      printf("%lld\n", S(b) - S(a - 1));
    }else{
      U(a, (long long)b - arr[a]);
      arr[a] = (long long)b;
    }
  }
	return 0;
}

