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

#define max_v 220000
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

int d[max_v * 4], n, m, s;

int Q_m(int qL, int qR, int k, int L, int R){
  if(qR <= L || R <= qL || R <= L) return int_max;
  if(qL <= L && R <= qR) return d[k];
  int mid = (L + R) / 2;
  return min(Q_m(qL, qR, LC(k), L, mid), Q_m(qL, qR, RC(k), mid, R));
}

void U(int p, int val, int k, int L, int R){
  if(p < L || R <= p || R <= L) return ;
  if(L + 1 == R){
    assert(L == p);
    d[k] = val;
    return ;
  }
  int mid = (L + R) / 2;
  U(p, val, LC(k), L, mid);
  U(p, val, RC(k), mid, R);
  d[k] = min(d[LC(k)], d[RC(k)]);
}


int main(){
  
  scanf("%d%d", &n, &m);
  memset(d, 0x3f, sizeof(d));
  s = pow_2(LOG2(n));
  for(int i = 0; i<n; i++){
    int a;
    scanf("%d", &a);
    U(i, a, 0, 0, s);
  }
  while(m--){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", Q_m(a - 1, b, 0, 0, s));
  }


	return 0;
}

