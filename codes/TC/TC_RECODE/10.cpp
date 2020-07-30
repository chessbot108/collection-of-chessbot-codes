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

/**
 *  resource:   SH   WO   BR  OR  WH
 *  settlement: 1    1    1   0   1
 *  road:       0    1    1   0   0
 *  city:       0    0    0   3   2
 *  town hall:  3    0    0   3   3
 *  
 *  here's the plan. biuld as many settlements as i can
 *  and merge the cost for a settlement and the cost for a road
 *
 *  then depening on the amount of sheep i have biuld a town hall
 *
 *  then using the remaining resources make cities
**/

int main(){
  int SH, WO, BR, OR, WH;
  scanf("%d%d%d%d%d", &SH, &WO, &BR, &OR, &WH);
  int settlements = min(min(SH, WO/3), min(BR/3, WH));
  SH -= settlements, WO -= settlements*3, BR -= settlements*3, WH -= settlements;
  if(SH >= 1 && WO >= 1 && BR >= 1 && WH >= 1){ 
    settlements++;
    SH--, WO--, BR--, WH--;
  }
  int townhall = (SH >= 3 && OR >= 3 && WH >= 3) ? 1 : 0;
  SH -= townhall*3, OR -= townhall*3, WH -= townhall*3;
  int cities = min(min(settlements, OR/3), WH/2);
  //printf("%d %d %d\n", settlements, townhall, cities);
  printf("%d\n", settlements + cities + townhall*2);
	return 0;
}

