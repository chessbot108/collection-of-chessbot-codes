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

long long arr[max_v], pre[max_v], x;
int n;

long long Q(int l, int r){// [l, r]
  return pre[r] - pre[l];
}

int main(){
	scanf("%d%lld", &n, &x);
  for(int i = 0; i<n; i++){
    scanf("%d", &arr[i]);
    pre[i + 1] = pre[i] + arr[i];
  }

  int s = 0, e = 1, ans = 0;
  while(e <= n){
    //printf("%d %d %d %d\n", s, e, Q(s, e), ans);
    if(Q(s, e) == x) ans++;
    if(Q(s, e) < x) e++;
    else s++;
    
  }
  printf("%d\n", ans);


	return 0;
}

