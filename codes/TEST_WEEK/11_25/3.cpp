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

#define max_v 51000
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
//50% for a[i]^2
//loop over all possible values of a and all for b
//and just keep a cnt of how many ways there are
//to make the final amount

int a[max_v], b[max_v], ans[max_v * 2];
int n, res = 0;

int main(){
	scanf("%d", &n);
  for(int i = 0; i<n; i++){
    int A; scanf("%d", &A);
    a[A]++;
  } 

  for(int i = 0; i<n; i++){
    int B; scanf("%d", &B);
    b[B]++;
  }
  
  for(int i = 1; i<=5e3; i++){
    for(int j = 1; j<=5e3; j++){
      ans[i + j] += min(a[i], b[j]);
    }
  }
  for(int i = 1; i<=1e4; i++){
    res = max(res, ans[i]);
    //if(i <= 20) printf("there are %d ways to make %d\n", ans[i], i);
  }
  printf("%d\n", res); 

	return 0;
}

