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

#define max_v 510000
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

int sum[max_v * LOGN], lc[max_v * LOGN], rc[max_v * LOGN];
int arr[max_v], srt[max_v], root[max_v], n, s, q, ind;

int get_ind(int key){
  return lower_bound(srt, srt + n, key) - &srt[0];
}

void dup(int& k){
  ind++;
  sum[ind] = sum[k];
  lc[ind] = lc[k];
  rc[ind] = rc[k];
  k = ind;
}

void U(int p, int val, int&k, int L, int R){
  
}

void pre_process(){
  s = pow_2(LOG2(n));
  ind = s*2;
  root[0] = 0;
  for(int i = 0; i < s - 1; i++){
    srt[i] = arr[i];
    lc[i] = LC(i);
    rc[i] = RC(i);
  }

  srt(srt, srt + n);

  for(int i = 1; i<=n; i++){
    root[i] = root[i - 1];
    
  }
  
}

int main(){
	
	return 0;
}

