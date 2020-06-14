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

#define max_v 210000
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)
#define LOG2(n) ((int)ceil(log2(n)))
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int d[max_v * 2], add[max_v * 2];

class seg_tree{
  int s, n;
  void A(int l, int r, int k, int L, int R, int val){
    if(R <= L || R <= l || r <= L) return ;
    int lc = k*2 + 1, rc = k*2 + 2, mid = (L + R)/2;
    if(l <= L && R <= r){
      add[k] += val;
    }else{
      A(l, r, lc, L, mid, val);
      A(l, r, rc, mid, R, val);
      d[k] = min(d[lc] + add[lc], d[rc] + add[rc]);
    }
  
  }
  
  int Q_min(int l, int r, int k, int L, int R){
    //printf("%d %d %d %d %d\n", l, r, k, L, R);
    if(R <= l || r <= L) return int_max;
    if(l <= L && R <= r) return d[k] + add[k];
    
    int lc = k*2 + 1, rc = k*2 + 2, mid = (L + R)/2;
    return add[k] + min(Q_min(l, r, lc, L, mid), Q_min(l, r, rc, mid, R));
  }
  
  public:
    seg_tree(int s, int* arr){
      this->n = pow_2(LOG2(s));
      memset(d, 0x3f, sizeof(d));
      for(int i = n - 1; i<n + s - 1; i++){
        d[i] = arr[i - (n - 1)];
      }
       
      for(int i = n - 2; i>= 0; i--){
        d[i] = min(d[i*2 + 1], d[i*2 + 2]);
      }
    }
    
    void range_update(int l, int r, int val){
      A(l, r, 0, 0, n, val);
    }
    
    int query_min(int l, int r){
      return Q_min(l, r, 0, 0, n);
    }

    void print_all(){
      for(int i = 0; i<n*2 ; i++)
        printf("%d ", d[i]);
      puts("");
    }
};


struct interval{
  int start, end, dur;
  interval(int a, int b){
    start = a, end = b, dur = b - a;
  }

  interval(){}
  
  bool operator < (const interval& b) const{
    if(end == b.end)
    	return dur < b.dur;
    return end < b.end;
  }
};

vector<interval> intervals;
int arr[max_v];
int main(){
  int n, q; 
  scanf("%d%d", &n, &q);
  for(int i = 0; i<n; i++)
    scanf("%d", &arr[i]);

  while(q--){
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    
    intervals.push_back(interval(a, b));
  }
  
  sort(intervals.begin(), intervals.end());
  seg_tree S(n, arr);
  //S.print_all();
  int total = 0;

  for(int i = 0; i<intervals.size(); i++){
    int a = intervals[i].start, b = intervals[i].end;
    //printf("%d %d\n", a, b);
 
    if(S.query_min(a, b) == 0) cont;
    total++;
    S.range_update(a, b, -1);
    //printf("TAKE\n"); 
    //S.print_all();
  }
    
  printf("%d\n", total);


	return 0;
}

