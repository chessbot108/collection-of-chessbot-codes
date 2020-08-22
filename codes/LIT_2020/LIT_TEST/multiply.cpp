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

const long long mod = (long long)1e9 + 7;

long long mult[max_v * 4][3]; //0 -> even, 1 -> odd
long long arr[max_v];
int n, m, s;

long long S(int qL, int qR, int k, int L, int R){
  //printf("%d %d %d %d %d %d\n", qL, qR, k, L, R, mult[k][0]);
  if(qR <= L || R <= qL || R <= L) return 1ll;
  if(qL <= L && R <= qR) return mult[k][(L - qL) % 2] % mod;
  int mid = (L + R) / 2;
  return (S(qL, qR, LC(k), L, mid) * S(qL, qR, RC(k), mid, R)) % mod;
}

void comp(){
  s = pow_2(LOG2(n));
  for(int i = (s - 1); i < s + n - 1; i++){
    mult[i][0] = arr[i - (s - 1)];
    mult[i][1] = 1ll;
    //printf("%d %d %d\n", arr[i - (s - 1)], mult[i][0], mult[i][1]);
  }

  for(int i = (s - 2) / 2; i<s - 1; i++){
    mult[i][0] = mult[LC(i)][0];
    mult[i][1] = mult[RC(i)][0];
  }
  

  for(int i = (s - 2)/2 -1; i >= 0; i--){
    mult[i][0] = (mult[LC(i)][0] * mult[RC(i)][0]) % mod;
    mult[i][1] = (mult[LC(i)][1] * mult[RC(i)][1]) % mod;
  }
  
}

int main(){
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    scanf("%lld", &arr[i]);
  }
  comp();
  scanf("%d", &m);
  while(m--){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%lld\n", S(a - 1, b, 0, 0, s));
  }
  
	return 0;
}

