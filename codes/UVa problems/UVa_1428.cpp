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

#define max_v 110000
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)

using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}
int s[max_v * 4];
class BIT{
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

    void print(){
      for(int i = 1; i<=n; i++){
        printf("%d\n", s[i]);
      }
      puts("");
    } 

};
int arr[22000], l[22000], r[22000], L[22000], R[22000];
//l[i] -> people left of i
//r[i] -> people right of i


int main(){
  //setIO("a");
	int T;
  scanf("%d", &T);
  while(T--){
    int n;
    scanf("%d", &n);
    
    memset(arr, 0, sizeof(arr));
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    memset(R, 0, sizeof(R));
    memset(L, 0, sizeof(L));

    for(int i = 0; i<n; i++){
      scanf("%d", &arr[i]);
    }
    
    BIT lB(max_v);

    for(int i = 0; i<n; i++){
      l[i] = lB.sum(arr[i]);
      L[i] = lB.sum(arr[i], max_v);
      lB.update(arr[i], 1);
    }
    
    BIT rB(max_v);

    for(int i = n-1; i>=0; i--){
      r[i] = rB.sum(arr[i]);
      R[i] = lB.sum(arr[i], max_v);
      rB.update(arr[i], 1);
    }

    long long total = 0;
    for(int i = 0; i<n; i++){
      int temp = (l[i] * (n - i - (r[i] + 1)));
      temp += (r[i] * (i - l[i]));
      total += (long long) temp;
      //printf("%d %d %d %d\n", l[i], r[i], L[i], R[i]);
    }
    
    printf("%lld\n", total);

  }
	return 0;
}

