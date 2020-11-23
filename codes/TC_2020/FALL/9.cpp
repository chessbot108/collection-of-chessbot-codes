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

#define max_v 1100000
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

int st[max_v * 4], arr[max_v];
int s, n, m, k;
void make_tree(){
  s = pow_2(LOG2(n));
  for(int i = s - 1; i < s + n - 1; i++){
    st[i] = arr[i - (s - 1)];
  }
  for(int i = s - 2; ~i; i--){
    st[i] = max(st[LC(i)], st[RC(i)]);
  }
}

int M(int qL,int qR, int k, int L, int R){
  if(qR <= L || R <= qL || R <= L) return 0;
  if(qL <= L && R <= qR) return st[k];
  int mid = (L + R) / 2;
  return max(M(qL, qR, LC(k), L, mid), M(qL, qR, RC(k), mid, R));
}



int main(){
	scanf("%d%d%d", &n, &m, &k);
  for(int i = 0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  make_tree();
  while(m--){
    int a;
    scanf("%d", &a);
    printf("%d\n", M(a - 1, a + k - 1, 0, 0, s));
  }
	return 0;
}

