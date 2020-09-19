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

int arr[max_v], sum[max_v * 4], n, s;

void U(int p, int val, int k, int L, int R){
  if(p < L || R <= p || R <= L) return ; 
  if(L + 1 == R){
    assert(L == p);
    sum[k] += val;
    return ;
  }
  int mid = (L + R) / 2;
  U(p, val, LC(k), L, mid);
  U(p, val, RC(k), mid, R);
  sum[k] = sum[LC(k)] + sum[RC(k)];
}

int bin_search(int kth, int k, int L, int R){
  //printf("%d %d %d %d %d\n", kth, k, L, R, sum[LC(k)]);
  if(L + 1 == R) return L;
  int mid = (L + R) / 2;
  assert(kth >= 0);
  if(kth < sum[LC(k)]){
    return bin_search(kth, LC(k), L, mid);
  }else{
    return bin_search(kth - sum[LC(k)], RC(k), mid, R);
  }
}

int main(){
	scanf("%d", &n);
  s = pow_2(LOG2(n));
  for(int i = 0; i<n; i++){
    scanf("%d", &arr[i]);
    U(i, 1, 0, 0, s);
  }

  for(int i = 0; i<n; i++){
    int a, ans = 0;
    scanf("%d", &a);
    assert(sum[0] >= a);
    ans = bin_search(a - 1, 0, 0, s);
    printf("%d ", arr[ans]);
    U(ans, -1, 0, 0, s);
  }
  
	return 0;
}

