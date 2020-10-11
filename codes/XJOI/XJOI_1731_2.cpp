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
//time to redeem myself by coding cereal

int f[max_v], s[max_v], cer[max_v], cow[max_v];
//first fav, second fav, f(cow) -> cereal, f(cereal) -> cow

int ans[max_v], n, m, cnt = 0;

int take(int c, int C){//give cow c cereal C
  if(cow[C] == 0){
    cow[C] = c;
    cer[c] = C;
    return 1;
  }else if(cow[C] < c){
    return 0;
  }else{
    int temp = cow[C];
    cow[C] = c;
    cer[c] = C;
    if(C == s[temp]) return 0; //its doomed;
    return take(temp, s[temp]);
  }
}


int main(){
	scanf("%d%d", &n, &m);
  for(int i = 1; i<=n; i++){
    scanf("%d%d", &f[i], &s[i]);
  }
   
  for(int i = n; i > 0; i--){

    ans[i] = min(ans[i + 1] + take(i, f[i]), m);
    /**
    for(int i = 1; i<=n; i++){
      printf("cow %d holds %d\n", i, cer[i]);
    }
    for(int i = 1; i<=m; i++){
      printf("cow %d holds %d\n", cow[i], i);
    }
    **/
  }

  for(int i = 1; i<=n; i++) printf("%d\n", ans[i]);

	return 0;
}

