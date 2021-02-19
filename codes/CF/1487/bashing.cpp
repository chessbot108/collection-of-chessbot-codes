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

#define max_v 1100
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


int main(){
  const int n = 9;
  int cnt = 0;
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      if((i*i -j) * (i*i -j) == i*i + j*j && i && (i*i -j) > 0 && i < j){
        //cout << i << " " << j << " " << (i*i -j) << endl;
        cnt++;
      }
    }
  }
  int est = (int)floor(sqrt(n*2));
  est -= (1 - est%2);
  cout << cnt  << " " << est/2 << endl;
	return 0;
}

