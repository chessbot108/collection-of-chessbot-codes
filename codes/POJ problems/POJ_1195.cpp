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
#define LSB(x) ((x) & (-(x)))
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

long long Bi[max_v][max_v];

class _BIT{
  int n;
  void U(int x, int y, int val){
    for(int i = x; i<=n; i += LSB(i)){
      for(int j = y; j<=n; j += LSB(j)){
        Bi[i][j] += val;
      }
    }
  }
  
  long long S(int x, int y){
    long long val = 0;
    for(int i = x; i>0; i -= LSB(i)){
      for(int j = y; j>0; j -= LSB(j)){
        val += Bi[i][j];
      }
    }
    return val;
  }

  public:
    _BIT(int n){
      this->n = n;
      memset(Bi, 0, sizeof(Bi));
    }
    
    _BIT(){}

    void update(int x, int y, int val){
      x++, y++;
      U(x, y, val);
    }

    long long sum(int x1, int y1, int x2, int y2){
      x2++, y2++;
      return (S(x1, y1) + S(x2, y2)) - (S(x1, y2) + S(x2, y1));
    }


};


int main(){
	int com;
  _BIT B;
  while(scanf("%d", &com)){
    if(com == 0){
      int n;
      scanf("%d", &n);
      B = _BIT(n);
    }else if(com == 3){
      break;
    }else if(com == 1){
      int x, y, v;
      scanf("%d%d%d", &x, &y, &v);
      B.update(x, y, v);
    }else if(com == 2){
      int L, b, R, T;
      scanf("%d%d%d%d", &L, &b, &R, &T);
      printf("%lld\n", B.sum(L, b, R, T));
    }
  

  }
	return 0;
}

