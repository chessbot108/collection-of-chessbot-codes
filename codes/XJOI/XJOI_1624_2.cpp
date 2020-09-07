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

list<int> arr[max_v];
int occ[max_v], plates[max_v];
int n;


int main(){
	scanf("%d", &n);
  for(int i = 1; i<=n; i++){
    scanf("%d", &plates[i]);
  }
  int ans = 0, maxi = 0;
  for(int i = 1; i<=n; i++){
    int x = plates[i];
    if(x < maxi){ans = i; break;}
    for(int j = x; j > 0 && occ[j] == 0; j--){
      occ[j] = x; //setting it for the next inserted nodes
    }

    while(arr[occ[x]].size() && x > arr[occ[x]].back()){
      maxi = max(maxi, arr[occ[x]].back());
      arr[occ[x]].pop_back();
    }
    arr[occ[x]].push_back(x);
  }

  printf("%d\n", ans - 1); //stupid problem. cost me half my braincells. cowland was easier. for 50 test cases that is

	return 0;
}

