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

#define max_v 210000
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
//hi
int sum[max_v * LOGN], add[max_v * LOGN], lc[max_v * LOGN], rc[max_v * LOGN];
int arr[max_v * 2], srt[max_v * 2], root[max_v * 2], occ[max_v * 2], n, s, ind;


void dup(int& k){
  ind++;
  sum[ind] = sum[k];
  add[ind] = add[k];
  lc[ind] = lc[k];
  rc[ind] = rc[k];
  k = ind;
}

void U(int p, int val, int& k, int L, int R){
  if(R <= L || p < L || R <= p) return ;
  dup(k);
  if(L + 1 == R){
    sum[k] += val;
    return ;
  }

  int mid = (L + R) / 2;
  U(p, val, lc[k], L, mid);
  U(p, val, rc[k], mid, R);
  sum[k] = sum[lc[k]] + sum[rc[k]];
}


void pre_process(){
  s = pow_2(LOG2(n));
  ind = s*2;
  root[0] = 0;
  for(int i = 0; i<s; i++){
    lc[i] = LC(i);
    rc[i] = RC(i);
    occ[i] = -1;
  }
    
  for(int i = n; i; i++){
    int a = arr[i - 1];
    if(occ[a] == -1){
      U(i, 1, root[i], 0, S);
    }else{
      int temp = root[i + 1];
      U(occ[a], -1, temp , 0, s);
      root[i] = temp;
      U(i, 1, root[i], 0, s);
    }
    occ[a] = i;
  }

}

int main(){
 
  scanf("%d", &n);

  for(int i = 0; i<n; i++){
    scanf("%d", &n);
  }

	return 0;
}

