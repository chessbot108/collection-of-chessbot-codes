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
#define int_max 0x3f3f3f3f
#define cont continue
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

long long st[max_v * 4];
long long f[max_v], s[max_v], m, ans = (long long) 1e9 + 7;
int n, k;

long long S(int qL, int qR, int k, int L, int R){
  if(qR <= L || R <= qL || R<= L) return 0ll;
  if(qL <= L && R <= qR) return st[k];
  int mid = (L + R) / 2;
  return max(S(qL, qR, LC(k), L, mid), S(qL, qR, RC(k), mid, R));
}

void make_tree(){
  k = pow_2(LOG2(n));
  for(int i = k - 1; i<k + n - 1; i++){
    st[i] = s[i - (k - 1)];
  }
  for(int i = k - 2; ~i; i--){
    st[i] = max(st[LC(i)], st[RC(i)]);
  }
}


int main(){
	
  scanf("%d%lld", &n, &m);
  for(int i = 0; i<n; i++){
    scanf("%lld%lld", &f[i], &s[i]);
  }   
  make_tree();
  long long tot = 0;
  int start = 0;
  for(int i = 0; i<n; i++){
    tot += f[i];
    while(tot >= m){
      ans = min(ans, S(start, i + 1, 0, 0, k));
      tot -= f[start++];
    }
  }
  printf("%lld\n", ans);
	return 0;
}

