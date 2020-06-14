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
inline int LG_pow2(int n){
  return pow_2((int)ceil(log2(n)));
}

long long sub[max_v*2], sum[max_v*2], add_s[max_v * 2];

class seg_tree{
  int t[max_v * 2]; //min 
  int d[max_v * 2]; //max
  int add[max_v * 2];

  int n, s;

  int Q_min(int l, int r, int k, int L, int R){ //l and r are the query, k is the index, L and R are k's interval
    //printf("%d %d %d %d %d %d\n", l+1, r+1, k, L+1, R+1, (int)(l <= L && R <= r)); 
    if(R <= l || r <= L) return int_max;
    if(l <= L && R <= r) return t[k] + add[k];
    int mid = (L + R) / 2, lc = k*2 + 1, rc = k*2 + 2;
     
    return add[k] + min(Q_min(l, r, lc, L, mid), Q_min(l, r, rc, mid, R));
  }
  
  int Q_max(int l, int r, int k, int L, int R){ //l and r are the query, k is the index, L and R are k's interval
    printf("%d %d %d %d %d %d\n", l+1, r+1, k, L+1, R+1, (int)(l <= L && R <= r)); 
    if(R <= l || r <= L) return -int_max;
    if(l <= L && R <= r) return d[k] + add[k];
    int mid = (L + R) / 2, lc = k*2 + 1, rc = k*2 + 2;
     
    return add[k] + max(Q_max(l, r, lc, L, mid), Q_max(l, r, rc, mid, R));
  }
  
  long long Q_s(int l, int r, int k, int L, int R){
   
     printf("%d %d %d %d %d %d\n", l+1, r+1, k, L+1, R+1, (int)(l <= L && R <= r)); 
      
    if(R <= l || r <= L) return 0;
    if(l <= L && R <= r) return add_s[k] + sum[k];
    int mid = (L + R) / 2, lc = k*2 + 1, rc = k*2 + 2;
   
    return add_s[k] + Q_s(l, r, lc, L, mid) + Q_s(l, r, rc, mid, R);
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
      d[k] = max(d[lc] + add[lc], d[rc] + add[rc]);     
      sum[k] = sum[lc] + sum[rc] + add_s[lc] + add_s[rc]; 
    }

  }

  public:
    seg_tree(int* arr, int s){
      n = LG_pow2(s);
      this->s = s;
      
      memset(t, byte_max, sizeof(t));
      memset(add, 0, sizeof(add));
      memset(add_s, 0, sizeof(add_s));
      memset(d, 0x8f, sizeof(d));
      memset(sum, 0, sizeof(sum));
      memset(sub, 0, sizeof(sub));

      for(int i = n - 1; i < n + s - 1; i++){
        t[i] = arr[i - (n - 1)];
        d[i] = arr[i - (n - 1)];
        sub[i] = 1;
        sum[i] = (long long)arr[i - (n - 1)];
      }

      for(int i = n - 2; i >= 0; i--){
        t[i] = min(t[i*2 + 1], t[i*2 + 2]);
        d[i] = max(d[i*2 + 1], d[i*2 + 2]);
        sum[i] = sum[i*2 + 1] + sum[i*2 + 2];
        sub[i] = sub[i*2 + 1] + sub[i*2 + 2];
      }
      
    }
    
   long long query_sum(int l, int r){
      return Q_s(l, r, 0, 0, n); 
    }
    
    int query_min(int l, int r){
      return Q_min(l, r, 0, 0, n);  
    }
    
    int query_max(int l, int r){
      return Q_max(l, r, 0, 0, n);
    }

    void udpate(int k, int i){ //k is the index, i is the new value
      t[n + k - 1] = i;
      sum[n + k - 1] = (long long)i;
      k += n - 1;
      while(k){
        k = (k - 1) / 2;
        int lc = k*2 + 1, rc = k*2 + 2;
        t[k] = min(t[lc] + add[lc], t[rc] + add[rc]);
        d[k] = max(d[lc] + add[lc], d[rc] + add[rc]);
        sum[k] = sum[lc] + sum[rc] + add_s[lc] + add_s[rc];
      }
    }
    
    void range_udpate(int l, int r, int val){ //add val to all the values between [l, r)
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
int a[max_v];
int main(){
	int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    scanf("%d", &a[i]);
  }

  seg_tree S(a, n);

  int x;
  while(true){
    scanf("%d", &x);

    if(x == -1) break;
    else if(x == 1){
      int l, r;
      scanf("%d%d", &l, &r);
      l--; r--;
      printf("%d\n", S.query_min(l, r));
    }else if(x == 2){
      int i, k;
      scanf("%d%d", &i, &k);
      i--; 
      S.udpate(i, k);
    }else if(x == 3){
      int l, r, k;
      scanf("%d%d%d", &l, &r, &k);
      l--; r--; 
      S.range_udpate(l, r, k);
    }else if(x == 4){
      S.print_leaves();
    }else if(x == 5){
      S.print_all();
    }else if(x == 6){
      int a, b;
      scanf("%d%d", &a, &b);
      a--, b--;
      printf("%lld\n", S.query_sum(a, b));
    }else if(x == 7){
      int a, b;
      scanf("%d%d", &a, &b);
      a--, b--;
      printf("%d\n", S.query_max(a, b));
    }


  }


	return 0;
}

