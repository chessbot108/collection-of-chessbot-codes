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

#define max_v 1100
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)

using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

multiset<long long> ms;

int main(){
	
  int q;
  scanf("%d", &q);
  while(q--){
    int com;
    long long a;
    scanf("%d%lld", &com, &a);
    if(com <= 0) break; //debug
    if(com == 1){
      ms.insert(a);
    }else if(com == 2){
      ms.erase(ms.lower_bound(a));
    }else if(com == 5){
      auto it = ms.lower_bound(a);
      it--;
      printf("%lld\n", *it);
    }else if(com == 6){
      auto it  = ms.lower_bound(a + 1LL);
      printf("%lld\n", *it);
    }
  }



	return 0;
}

