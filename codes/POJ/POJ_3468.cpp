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

#define max_v 110000
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)
#define LSB(x) (((-(x)) & (x)))

using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}


class BIT{
  long long B1[max_v], B2[max_v], n;
  
  void U(long long * B, int k, long long val){
    if(k > n) return ;
    B[k] += val;
    U(B, k + LSB(k), val);
  }
  
  void S(long long * B, long long& val, int k){
    if(!k) return ;
    val += (long long) B[k];
    S(B, val, k - LSB(k));
  }

  public:
    BIT(int n){
      this->n = n;
      memset(B1, 0, sizeof(B1));
      memset(B2, 0, sizeof(B2));
    }

    void update(int l, int r, long long val){//queries/updates will be assumed to be excluisve [a, b) and 0 based in nature
      l++;
      U(B1, l, val);
      U(B1, r + 1, -1LL * val); 
      U(B2, l, val * (l - 1LL)); 
      U(B2, r + 1, (-1LL * val) * (r)); 
    }
    
    void update(int l, int val){
      //assert(l != 0);
      update(l, l + 1, val);
    }

    long long sum(long long * B, int ind){
      long long temp = 0;
      S(B, temp, ind);
      return temp;
    }

    long long sum(int l){
      return (long long)(sum(B1, l) * l) - sum(B2, l); 
    }

    long long sum(int l, int r){
      return sum(r) - sum(l);
    }
    
    
};

long long arr[max_v];

int main(){
  int n, q;
  scanf("%d%d", &n, &q);
  for(int i = 0; i<n; i++)
    scanf("%lld", &arr[i]);
  
  BIT B(n);

  for(int i = 0; i<n; i++)
    B.update(i, arr[i]);

  while(q--){
    char str[10];
    scanf("%s", str);
    if(str[0] == 'Q'){
      int l, r;
      scanf("%d%d", &l, &r);
      l--;
      printf("%lld\n", B.sum(l, r));
    }else{
      int l, r;
      long long v;
      scanf("%d%d%lld", &l, &r, &v);
      l--;
      B.update(l, r, v);
    }


  }

	return 0;
}

