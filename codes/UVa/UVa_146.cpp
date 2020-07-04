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

#define max_v 100
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
char str[max_v];


int main(){
	while(scanf("%s", str)){
    if(str[0] == '#') break;
    int n = strlen(str);
    int sw = n - 1, ind = n - 1;

    while(sw && str[sw] <= str[sw - 1]) sw--;
    
    if(!sw){
      printf("No Successor\n");
      cont;
    }
    
    while(str[sw - 1] >= str[ind]) ind--;

    assert(ind > sw - 1);
    

    swap(str[sw - 1], str[ind]);

    sort(str + sw, str + n);
    printf("%s\n", str);
    memset(str, 0, sizeof(str));

  }
	return 0;
}

