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

#define max_v 410000
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)

using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}
inline int LG_pow2(int n){
  return pow_2((int)ceil(log2(n)));
}

long long sub[max_v*2], sum[max_v*2], add_s[max_v * 2];

class seg_tree{
  int t[max_v * 2];
  int add[max_v * 2];
  int n, s;

  int Q(int l, int r, int k, int L, int R){ //l and r are the query, k is the index, L and R are k's interval
    //rintf("%d %d %d %d %d %d\n", l+1, r+1, k, L+1, R+1, (int)(l <= L && R <= r)); 
    if(R <= l || r <= L) return int_max;
    if(l <= L && R <= r) return t[k] + add[k];
    int mid = (L + R) / 2, lc = k*2 + 1, rc = k*2 + 2;
     
    return add[k] + min(Q(l, r, lc, L, mid), Q(l, r, rc, mid, R));
  }
  
  long long Q_s(int l, int r, int k, int L, int R){
   
    //intf("%d %d %d %d %d %d, {%d %d %lld %lld}\n", l+1, r+1, k, L+1, R+1, (int)(l <= L && R <= r), t[k], add[k], sum[k], add_s[k]); 
      
    if(R <= l || r <= L) return 0;
    if(l <= L && R <= r) return add_s[k] + sum[k];
    int mid = (L + R) / 2, lc = k*2 + 1, rc = k*2 + 2;
   
    return ((long long) add[k]* (long long)(min(R, r) - max(L, l))) + Q_s(l, r, lc, L, mid) + Q_s(l, r, rc, mid, R);
  }


  void A(int l, int r, int k, int L, int R, int val){
    if(R <= L || R <= l || r <= L) return;
    int lc = k*2 + 1, rc = k*2 + 2;
    int mid = (L + R) / 2;
    if(l <= L && R <= r){
      add[k] += val;
      add_s[k] += (long long)val * sub[k]; 
    }else{
      A(l, r, lc, L, mid, val);
      A(l, r, rc, mid, R, val);
      t[k] = min(t[lc] + add[lc], t[rc] + add[rc]);
      sum[k] = sum[lc] + sum[rc] + add_s[lc] + add_s[rc]; 
    }

  }

  public:
    seg_tree(int* arr, int s){
      n = LG_pow2(s);
      this->s = s;
      memset(t, byte_max, sizeof(t));

      for(int i = n - 1; i < n + s - 1; i++){
        t[i] = arr[i - (n - 1)];
        sub[i] = 1;
        sum[i] = (long long)arr[i - (n - 1)];
      }

      for(int i = n - 2; i >= 0; i--){
        t[i] = min(t[i*2 + 1], t[i*2 + 2]);
        sum[i] = sum[i*2 + 1] + sum[i*2 + 2];
        sub[i] = sub[i*2 + 1] + sub[i*2 + 2];
      }
      
    }
    
   long long query_sum(int l, int r){
      return Q_s(l, r, 0, 0, n); 
    }
    
    int query(int l, int r){
      return Q(l, r, 0, 0, n);  
    }
    
    void udpate(int k, int i){ //k is the index, i is the new value
      t[n + k - 1] = i;
      sum[n + k - 1] = (long long)i;
      k += n - 1;
      while(k){
        k = (k - 1) / 2;
        int lc = k*2 + 1, rc = k*2 + 2;
        t[k] = min(t[lc] + add[lc], t[rc] + add[rc]);
        sum[k] = sum[lc] + sum[rc] + add_s[lc] + add_s[rc];
      }
    }
    
    void range_update(int l, int r, int val){ //add val to all the values between [l, r)
      A(l, r, 0, 0, n, val);
    }

    void print_leaves(){
      for(int i = n - 1; i< n - 1 + s; i++) printf("%d ", t[i]);
      puts("");
    }
    
    void print_all(){
      for(int i = 0; i<n*2; i++) printf("%d ", t[i]);
      puts("");
    }

};

int arr[max_v];

int main(){
  setIO("haybales");
  int n, q;
  scanf("%d%d", &n, &q);
  for(int i = 0; i<n; i++){
   scanf("%d", &arr[i]); 
  }

  seg_tree S(arr, n);
  while(q--){
    char c[10];
    scanf("%s", c);
    
    char cmd = c[0];
    
    //(cmd == '-') break;

    if(cmd == 'M'){
      int a, b;
      scanf("%d%d", &a, &b);
      a--;
      printf("%d\n", S.query(a, b));
    }else if(cmd == 'S'){
      int a, b;
      scanf("%d%d", &a, &b);
      a--;
      printf("%lld\n", S.query_sum(a, b));
    }else{
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      a--;
      S.range_update(a, b, c);
    }
    // S.print_all();

  }

	return 0;
}

