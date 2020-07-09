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

int tag;
int lc[max_v], rc[max_v];
long long sum[max_v];
long long L[max_v], R[max_v], dL[max_v], dR[max_v]; //cap = weight
long long input(int& k, long long weight){
  k = tag++;
  if(weight != 0LL) return sum[k] = weight;
  scanf("%lld%lld%lld%lld", &L[k], &dL[k], &R[k], &dR[k]);
  return sum[k] = (input(lc[k], L[k]) + input(rc[k], R[k]));
}

bool solve(int k){
  if(lc[k] == 0 && rc[k] == 0) return true;
  //printf("%d * %d == %d * %d\n", dL[k], sum[lc[k]], dR[k], sum[rc[k]]);
  return solve(lc[k]) && solve(rc[k]) && (dL[k] * sum[lc[k]] == dR[k] * sum[rc[k]]);
}


int main(){
  //setIO("a");
  int T;
  scanf("%d", &T);
  while(T--){
    tag = 0;
    memset(lc, 0, sizeof(lc));
    memset(rc, 0, sizeof(rc));
    memset(L, 0, sizeof(L));
    memset(R, 0, sizeof(R));
    memset(sum, 0, sizeof(sum));
    memset(dR, 0, sizeof(dR));
    memset(dL, 0, sizeof(dL));
    int root = 0;
    input(root, 0);
    printf("%s\n", (solve(0)) ? "YES" : "NO");
    if(T) puts("");
  }
	return 0;
}

