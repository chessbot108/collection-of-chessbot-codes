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

#define max_v 110
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)
#define lsb(n) ((n)&(-(n)))
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}


int n;
int BIT[max_v][max_v][max_v];

void U(int x, int y, int z){
  for(int i = x; i<=n; i += lsb(i)){
    for(int j = y; j<=n; j += lsb(j)){
      for(int k = z; k<=n; k += lsb(k)){
        BIT[i][j][k] ^= 1;
      }
    }
  } 
}

int S(int x, int y, int z){
  int a = 0;
  for(int i = x; i > 0; i -= lsb(i)){
    for(int j = y; j > 0; j -= lsb(j)){
      for(int k = z; k > 0; k -= lsb(k)){
        a ^= BIT[i][j][k]; 
      }
    }
  }
  return (int)(a);
}


int main(){
  int q;
   while(~scanf("%d", &n)){
    //if(n < 0) break;
    scanf("%d", &q);
    memset(BIT, 0, sizeof(BIT));
    while(q--){
      int op;
      scanf("%d", &op);
      if(op == 0){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        printf("%d\n", S(x, y, z));
      }else{
        int a, b, c, d, e, f;
        scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
        d++, e++, f++;
        U(a, b, c);
        U(d, b, c);
        U(a, e, c);
        U(a, b, f);
        U(a, e, f);
        U(d, b, f);
        U(d, e, c);
        U(d, e, f);
      }
    }
  }
	return 0;
}

