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

#define max_v 5100
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

long long ans[max_v][max_v];
int arr[max_v], buckets[2100000];

int main(){
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  
  for(int i = n; ~i; i--){
    for(int j = i + 1; j<n; j++){
      ans[i][j] = (1e6 - arr[i] - arr[j] >= 0 && 1e6 - arr[i] - arr[j] <= 2e6) ? buckets[(int)1e6 - (arr[i] + arr[j])] : 0;
      buckets[(int)1e6 + arr[j]]++;
    }
    for(int j = i + 1; j<n; j++) buckets[arr[j] + (int)1e6]--;
  }
  
  for(int i = n - 1; ~i; i--){
    for(int j = i + 1; j<n; j++){
      ans[i][j] += ans[i + 1][j] + ans[i][j - 1] - ans[i + 1][j - 1]; //PIE
      //printf("%d %d -> %lld\n", i, j, ans[i][j]);
    }
  }

  while(m--){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%lld\n", ans[a - 1][b - 1]);
  }

	return 0;
}

