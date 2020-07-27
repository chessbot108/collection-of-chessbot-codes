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
  U(k + lsb(k));
}

int S(int k){
  if(!k) return 0;
  return BIT[k] + S(k - lsb(k));
}

void cdq(int l, int r){//[a, b) as i always do 
  if(l + 1 >= r) return ;
  int mid = (L + R) / 2;
  cdq(L, mid);
  cdq(mid, R);
  for(int i = l; i<r; i++){
    if(ins[arr[i]]) U(ins[arr[i]], -1); //best way i could come up with the clear the bit...
  }
  int i = l, j = mid;
  /**
  this part is bad for my brain.
  i am so glad it is unique keys
  counting i's inversions: S(ins[arr[i]]); //amount indexed left and lesser value and lesser time
  counting j's inversions: S*ins[arr[j]]); but sort backwards
  **/
  
  while(true){
    if(j >= r || i < mid(srt[i] < srt[j])){
      inv[srt[i]] = S(ins[srt[i]]);
      i++;
    }else{
      j++;
    }
    if(i >= mid && j >= r){
      assert(i == mid && j == r);
      break;
    }
  }
  
  for(int i = l; i<r; i++){
    if(ins[arr[i]]) U(ins[arr[i]], -1); //best way i could come up with the clear the bit...
  }
  
  while(true){
    if(
  }
  


}




int main(){
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++){
    scanf("%d", &arr[i]);
    ins[i] = 1;
  }

  for(int i = 0; i<m; i++){
    scanf("%d", &rem[i]);
    ins[rem[i]] = i + 1;
  }   
  
  return 0;
}

