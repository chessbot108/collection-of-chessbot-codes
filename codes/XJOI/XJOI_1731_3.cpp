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
//testing a new idea that is NOT kmp
//should be o(n) but i'm not sure

list<int> a, b;
char str[max_v], pat[max_v];

int main(){
  scanf("%s%s", str, pat);
  int n = strlen(str), m = strlen(pat);
  for(int i = 0; i<n; i++){
    if(str[i] == pat[0]) a.push_back(i);
  }
  for(int i = 1; i<m; i++){
    //printf("for letter %c, pat[%d]\n", pat[i], i);
    for(int x : a){
      //printf("\t%d ", x + 1);
      if(str[x + 1] == pat[i]){
        b.push_back(x + 1);
      }
    }
    a.swap(b);
    b.clear();
    //puts("");
  }
  printf("%d\n", 2 + a.front() - m);

	return 0;
}

