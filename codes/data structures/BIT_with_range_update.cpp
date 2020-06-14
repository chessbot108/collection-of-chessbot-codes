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
#define LSB(x) (((-(x)) & (x)))

using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}


class BIT{
  int B1[max_v], B2[max_v], n;
  
  void U(int * B, int k, int val){
    if(k > n) return ;
    B[k] += val;
    U(B, k + LSB(k), val);
  }
  
  void S(int * B, long long& val, int k){
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

    void update(int l, int r, int val){//queries/updates will be assumed to be excluisve [a, b) and 0 based in nature
      l++;
      U(B1, l, val);
      U(B1, r + 1, -1 * val); 
      U(B2, l, val * (l - 1)); 
      U(B2, r + 1, (-1 * val) * (r)); 
    }
    
    void update(int l, int val){
      //assert(l != 0);
      update(l, l + 1, val);
    }

    long long sum(int * B, int ind){
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
    
    void print(){
      for(int i = 0; i<=n; i++){
        printf("(%lld, %d, %d)\n ", sum(B1, i + 1), B1[i + 1], B2[i + 1]);
      }
      

      puts("");
    }
    

};

int arr[max_v];

int main(){
	int n, q;
  scanf("%d%d", &n, &q);
  
  for(int i = 0; i<n; i++)
    scanf("%d", &arr[i]);

  BIT B(n);

  for(int i = 0; i<n; i++){
    B.update(i, arr[i]);
  }

  while(q--){
    int com;
    scanf("%d", &com);
    if(com <= 0) break;
    if(com == 1){
      int l;
      scanf("%d", &l);
      l--;
      printf("%lld\n", B.sum(l));
    }else if(com == 2){
      int l, r;
      scanf("%d%d", &l, &r);
      l--, r--;
      printf("%lld\n", B.sum(l, r));
    }else if(com == 3){
      int l, r, val;
      scanf("%d%d%d", &l, &r, &val);
      l--, r--;
      B.update(l, r, val);
    }else if(com == 4){
      B.print();
    }

  }


	return 0;
}

