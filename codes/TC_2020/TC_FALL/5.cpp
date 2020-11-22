//failed attempt at 5 by me. our submission was 5.py from miles


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

#define max_v 20
#define int_max 0x3f3f3f3f
#define cont continue
#define pow_2(n) (1ll << (n))
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

char str[max_v];
int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    long long a, b, tot = 0ll;
    memset(str, 0, sizeof(str));
    scanf("%lld%s", &a, str);
    //printf("%s, %d\n", str, strlen(str));
    for(int i = 0; i<strlen(str); i++){
      tot = tot*a + (long long)(str[i] - '0');
    
    }
     

    //printf("%d %lld\n", tot, (int)floor(log2(tot)));
    for(long long i = (long long)log2(tot); ~i; i--){
      //printf("\n%d \n", i);
      printf("%d", (pow_2(i)&tot) ? 1 : 0);
    }

    puts("");
  }
	return 0;
}

