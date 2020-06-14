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
#include <unordered_map>
#include <unordered_set>
#include <functional>

#define max_v 1100
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)

using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

class BIT{
  int s[max_v];
  int n;

  void U(int a, int val){
    if(a > n) return;
    s[a] += val;
    U(a + (a & -a), val);
  }
  
  void S(int a, int& val){
    if(a == 0) return;
    val += s[a];
    S(a - (a& -a), val); 
  }
  
  public:
    BIT(int size){
      this->n = pow_2((int)(ceil(log2(size))));
      memset(s, 0, sizeof(s));
    }

    BIT(int size, int * arr){
      this->n = pow_2((int)(ceil(log2(size))));
      memset(s, 0, sizeof(s));

      for(int i = 1; i<=size; i++){
        U(i, arr[i - 1]);
      }
    }
    
    int sum(int a){
      int temp = 0;
      S(a, temp);
      return temp;
    }
    
    int sum(int a, int b){
      return sum(b) - sum(a);
    }

    void update(int a, int val){
      a++; //assume it is in 0-based
      U(a, val);
    }
};
int arr[max_v];
int main(){
	  
  int n;
  
  scanf("%d", &n);
  for(int i = 0; i<n; i++)
    scanf("%d", &arr[i]);

  BIT B(n, arr);
  
  int com;
  while(scanf("%d", &com)){
    if(com == -1) break;
    int a, b;
    if(com == 1){
      scanf("%d", &a);
      printf("%d\n", B.sum(a));
    }else if(com == 2){
      scanf("%d%d", &a, &b);
      a--;
      B.update(a, b);
    }else if(com == 3){
      scanf("%d%d", &a, &b);
      a--, b--;
      printf("%d\n", B.sum(a, b));
    }

  }




	return 0;
}

