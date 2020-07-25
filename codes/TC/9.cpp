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

#define max_v 1100000
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

int pre[max_v];


int main(){
	int n;
  cin >> n;
  for(int i = 0; i<n; i++){
    int a, b;
    cin >> a >> b;
    a++, b++; //remembr -- for the answer
    pre[a]++;
    pre[b + 1]--;
  }
  int ind, maxi = -1;
  for(int i = 1; i<(int)1e6 + 10; i++){
    pre[i] = pre[i - 1] + pre[i];
    if(pre[i] > maxi){
      pre[i] = maxi;
      ind = i;
    }
  }
  cout << ind - 1;
	return 0;
}

