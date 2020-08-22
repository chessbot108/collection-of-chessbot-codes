//copy by me
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

#define max_v 101000
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

int occ[max_v];

int t[max_v];
int n, m, l;


int main(){
	scanf("%d%d%d", &n, &m, &l);
  for(int i = 0; i<n; i++){
    scanf("%d", &t[i]);
  }
  
  for(int i = 0; i<n; i++){
    //printf("t[%d] = %d, and it became", i, t[i]);
    while(occ[t[i]] >= l) t[i]++;//will be less than M
    //printf("%d, with occ[t[i]] as %d\n", t[i], occ[t[i]]);
    for(int j = 0; j<m; j++){
      occ[t[i] + j]++;
    }
  } //O(n * m)
  
  int cnt = 0;
  //for(int i = 0; i<n; i++) printf("%d ", t[i]); puts("");
  for(int i = t[0]; i<t[n - 1]; i++){
    //printf("a");
    //printf("%d\n", occ[i]);
    if(!occ[i]) cnt++;
  }
  printf("%d\n", cnt);
	return 0;
}


