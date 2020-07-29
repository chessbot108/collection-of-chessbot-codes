
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
#include <queue>
#include <stack>
//#include <unordered_map>
//#include <unordered_set>
#include <functional>
 
#define max_v 110000
#define LOGN 50
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << (n))
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define LOG2(n) ((int)(ceil(log2((n)))))
using namespace std;
 
void setIO(const string& file_name){
    freopen((file_name+".in").c_str(), "r", stdin);
    freopen((file_name+".out").c_str(), "w+", stdout);
}
 
int n, m;
int rem[max_v], arr[max_v], ins[max_v], srt[max_v];
int BIT[50010], inv[max_v];
long long ans[max_v]; //smol brain moment. i forgot that 1e5^2 overflowed int
 
void U(int k, int v){
  if(k > 50010) return ;
  BIT[k] += v;
  U(k + lsb(k), v);
}
 
int S(int k){
  if(!k) return 0;
  return BIT[k] + S(k - lsb(k));
}
 
void cdq(int l, int r){//[a, b) as i always do
  if(l + 1 >= r) return ;
  int mid = (l + r) / 2;
  cdq(l, mid);
  cdq(mid, r);
  
  int i = l, j = mid, k = l;
  /**
  this part is bad for my brain.
  i am so glad it is unique keys
  counting i's inversions: S(ins[arr[i]]); //amount indexed left and lesser value and lesser time
  counting j's inversions: S*ins[arr[j]]); but sort backwards
  **/
  while(i < mid || j < r){
    //printf("%d\n", l);
    if((j >= r || arr[i] < arr[j]) && i < mid){
      inv[arr[i]] += S(ins[arr[i]]);
      srt[k++] = arr[i++];
    }else if(j < r){
      U(ins[arr[j]], 1);
      srt[k++] = arr[j++];
    }
  }
  
  if((r - mid) * 15 < 50010){
    for(i = mid; i<r; i++){
      U(ins[arr[i]], -1);
    }
  }else{
    memset(BIT, 0, sizeof(BIT));
  }
  
  j = r - 1, i = mid - 1, k = r - 1;
  while(i >= l || j >= mid){
    if((j < mid || arr[i] > arr[j]) && i >= l){
      U(ins[arr[i]], 1);
      i--, k--;
    }else if(j >= mid){
      inv[arr[j]] += S(ins[arr[j]]);
      j--, k--;
    } 
  }
   
  if((mid - l) * 15 < 50010){
    for(i = l; i<mid; i++){
      U(ins[arr[i]], -1);
    }
  }else{
    memset(BIT, 0, sizeof(BIT));
  }
 
  for(i = l; i<r; i++){
    arr[i] = srt[i];
  }
 
}
 
 
 
 
int main(){
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++){
    scanf("%d", &arr[i]);
    ins[i + 1] = 1;
  }
 
  for(int i = 0; i<m; i++){
    scanf("%d", &rem[i]);
    ins[rem[i]] = (m + 1) - i;
  }  
  cdq(0, n); 
  long long total = 0ll;
  for(int i = 1; i<=n; i++){
    if(ins[i] == 1) total += (long long)inv[i];
  }
  total /= 2ll;
  for(int i = m - 1; ~i; i--){
    ans[i] = (total += (long long)inv[rem[i]]);
  }
  /**
  for(int i = 1; i<=n; i++){
    printf("%d: %d %d\n", i, inv[i], ins[i]);
  }
  **/
  for(int i = 0; i<m; i++){
    printf("%lld\n", ans[i]);
  }
 
  return 0;
}
