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
//#include <unordered_map>
//#include <unordered_set>
#include <functional>

#define max_v 8800
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)

using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int n;
int arr[max_v], ans[max_v];

int main(){
  scanf("%d", &n);
  
  for(int i = 1; i<n; i++)
    scanf("%d", &arr[i]);

  for(int i = 0; i<n; i++){
    int m = -1;
    for(int j = 0; j<n; j++){
      if(arr[j] == 0) m = j;
    }
    assert(m != -1);
    ans[m] = i + 1;
    for(int j = m; j < n; j++){
      arr[j]--;
    }
  } 
  
  for(int i = 0; i<n; i++){
    printf("%d\n", ans[i]);
  }
	return 0;
}

