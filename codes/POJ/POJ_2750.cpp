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

#define max_v 410000
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


int sum[max_v], pre[max_v], suf[max_v] //d -> min
int arr[max_v];

int S(int qL, int qR, int k, int L, int R){
  if(R <= L || qR <= L || R <= qL) return 0;
  if(qL <= L && R <= qR) return sum[k];
  int mid = (L + R) / 2;
  return S(qL, qR, LC(k), L, mid) + S(qL, qR, RC(k), mid, R);
}

void U(int p, int val, int k, int L, int R){
  if(p < L || R <= p || R <= L) return ;
  if(L + 1 == R){
    assert(L == p);
    sum[k] = val;
    pre[k] = val;
    suf[k] = val;
    arr[k] = val;
    return ;
  }
  
  int mid = (L + R) / 2;
  U(p, val, LC(k), L, mid);
  U(p, val, RC(k), mid, R);
  pre[k] = min(pre[LC(k)], sum[LC(k)] + pre[RC(k)]);
  suf[k] = min(suf[RC(k)], sum[RC(k)] + suf[LC(k)]);

}



int main(){
	
	return 0;
}

