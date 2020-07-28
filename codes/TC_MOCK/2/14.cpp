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
int rem[max_v], arr[max_v], ins[max_v], unsrt[max_v], srt[max_v];
int BIT[50010], inv[max_v], ans[max_v];

void U(int k, int v){
  if(k >= 50010) return ;
  BIT[k] += v;
  assert(k);
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
  memset(BIT, 0, sizeof(BIT));
  int i = l, j = mid, k = l;
  /**
  this part is bad for my brain.
  i am so glad it is unique keys
  counting i's inversions: S(BIT2, ins[arr[i]]); //amount indexed left and lesser value and lesser time
  counting j's inversions: S(BIT1, ins[arr[j]]);
  **/
  while(true){
    //printf("%d\n", l);
    if((j >= r || arr[i] < arr[j]) && i < mid){
      inv[arr[i]] += S(ins[arr[i]]);
      srt[k++] = arr[i++];
    }else if(j < r){
      U(ins[arr[j]], 1);
      srt[k++] = arr[j++];
    }
    if(i >= mid && j >= r){
      assert(i == mid && j == r);
      break;
    }
  }
  memset(BIT, 0, sizeof(BIT));
  j = r - 1, i = mid - 1, k = r - 1;
  while(true){
    if((j < mid || arr[i] > arr[j]) && i >= l){
      U(ins[arr[i]], 1);
      unsrt[k--] = arr[i--];
    }else if(j >= mid){
      inv[arr[j]] += S(ins[arr[j]]);
      unsrt[k--] = arr[j--];
    }
    if(i < l && j < mid){
      assert(i == l - 1 && j == mid - 1);
      break;
    }
  }

  for(int i = l; i<r; i++){
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
  int total = 0;
  for(int i = 1; i<=n; i++){
    if(ins[i] == 1) total += inv[i];
  }
  total /= 2;
  for(int i = m - 1; ~i; i--){
    ans[i] = (total += inv[rem[i]]);
  }
  /** 
  for(int i = 1; i<=n; i++){
    printf("%d: %d %d\n", i, inv[i], ins[i]);
  }
  **/
  for(int i = 0; i<m; i++){
    printf("%d\n", ans[i]);
  }

  return 0;
}

