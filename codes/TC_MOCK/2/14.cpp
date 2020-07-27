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
int BIT[max_v], inv[max_v];

void U(int k, int v){
  if(k >= 55000) return ;
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
  printf("%d %d\n", l, r);
  int mid = (l + r) / 2;
  cdq(l, mid);
  cdq(mid, r);
  for(int i = l; i<r; i++){
    if(ins[arr[i]]){
      printf("ins[arr[%d]] where arr[i] = %d, is %d\n", i, arr[i], ins[arr[i]]);
      U(ins[arr[i]], -1);
    }//best way i could come up with the clear the bit...
  }
  int i = l, j = mid, k = l;
  /**
  this part is bad for my brain.
  i am so glad it is unique keys
  counting i's inversions: S(ins[arr[i]]); //amount indexed left and lesser value and lesser time
  counting j's inversions: S*ins[arr[j]]); but sort backwards
  **/
  //assert(false); 
  printf("now merging\n");
  while(true){
    printf("%d\n", l);
    if(j >= r || (i < mid && arr[i] < arr[j])){
      inv[arr[i]] += S(ins[arr[i]]);
      srt[l++] = arr[i++];
      printf("\tgoes to i, is adding\n");
    }else if(j < r){
      printf("\tgoes to j, is updating %d which the timestamp of %d\n", ins[arr[j]], arr[j]);
      U(ins[arr[j]], 1);
      srt[l++] = arr[j++];
    }
    if(i >= mid && j >= r){
      assert(i == mid && j == r);
      break;
    }
  }
  //assert(false); 
  for(int i = l; i<r; i++){
    if(ins[arr[i]]) U(ins[arr[i]], -1); //best way i could come up with the clear the bit...
  }
  j = r - 1, i = mid - 1, l = r - 1;
  while(true){
    if(j < mid || (i >= l && arr[i] > arr[j])){
      printf("%d, %d %d\n", i, arr[i], ins[arr[i]]);
      U(ins[arr[i]], 1);

      unsrt[l--] = arr[i--];
    }else{
      inv[arr[j]] += S(ins[arr[j]]);
      unsrt[l--] = arr[j--];
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
    ins[rem[i]] = i + 2;
  }   
  cdq(0, n);   
  return 0;
}

