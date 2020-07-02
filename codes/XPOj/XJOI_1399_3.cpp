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

#define max_v 66000
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)
#define LG_pow2(n) (pow_2((int)(ceil(log2(n)))))
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}
int d[max_v * 2]; //max
int add[max_v * 2];
  
class seg_tree{ 
  int n, s;

  int Q_max(int l, int r, int k, int L, int R){ //l and r are the query, k is the index, L and R are k's interval
    //printf("%d %d %d %d %d %d\n", l+1, r+1, k, L+1, R+1, (int)(l <= L && R <= r)); 
    if(R <= l || r <= L) return -int_max;
    if(l <= L && R <= r) return d[k] + add[k];
    int mid = (L + R) / 2, lc = k*2 + 1, rc = k*2 + 2;
     
    return add[k] + max(Q_max(l, r, lc, L, mid), Q_max(l, r, rc, mid, R));
  }
  

  void A(int l, int r, int k, int L, int R, int val){
    if(R <= L || R <= l || r <= L) return;
    int lc = k*2 + 1, rc = k*2 + 2;
    int mid = (L + R) / 2;
    if(l <= L && R <= r){
      add[k] += val;
    }else{
      A(l, r, lc, L, mid, val);
      A(l, r, rc, mid, R, val);
      d[k] = max(d[lc] + add[lc], d[rc] + add[rc]);     
    }

  }

  public:
    seg_tree(int* arr, int s){
      n = LG_pow2(s);
      this->s = s;
      
      memset(d, 0x8f, sizeof(d));
      
      for(int i = n - 1; i < n + s - 1; i++){
        d[i] = arr[i - (n - 1)];
      }

      for(int i = n - 2; i >= 0; i--){
        d[i] = max(d[i*2 + 1], d[i*2 + 2]);
      }
      
    }
    
    int query_max(int l, int r){
      return Q_max(l, r, 0, 0, n);
    }

    void udpate(int k, int i){ //k is the index, i is the new value
      d[n + k - 1] = i;
      k += n - 1;
      while(k){
        k = (k - 1) / 2;
        int lc = k*2 + 1, rc = k*2 + 2;
        d[k] = max(d[lc] + add[lc], d[rc] + add[rc]);
      }
    }
    
    void range_update(int l, int r, int val){ //add val to all the values between [l, r)
      A(l, r, 0, 0, n, val);
    }

    void print_leaves(){
      for(int i = n - 1; i< n - 1 + s; i++) printf("%d ", d[i]);
      puts("");
    }
    
    void print_all(){
      for(int i = 0; i<n*2; i++) printf("%d ", d[i]);
      puts("");
    }

};

int arr[max_v];

int main(){
  int C, S, Q;
  scanf("%d%d%d", &C, &S, &Q);
  
  seg_tree s(arr, C);//init all to 0

  while(Q--){
    int st, d, w; //start, dest, weight/cost
    scanf("%d%d%d", &st, &d, &w);
    
   // d++;
    if(s.query_max(st, d) + w > S) printf("N\n");
    else{
       printf("T\n");
       s.range_update(st, d, w);
    }

  }
  
	return 0;
}

