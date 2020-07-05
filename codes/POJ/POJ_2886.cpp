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

#define max_v 600000
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

char str[max_v][20];
int card[max_v], BIT[max_v], fac[max_v], ord[max_v], N, tag = 0;

long long mod(long long i, long long j){
  i += 100000010LL * j;
  assert(i > 0);
  return i % j;
}

void U(int i, int val){
  if(i > N + 10) return ;
  BIT[i] += val;
  U(i + lsb(i), val);
}

int S(int i){
  if(!i) return 0;
  return BIT[i] + S(i - lsb(i));
}


int bin_search(int kth){
  int l = 0, r = N;
  while(l + 1 < r){
    int mid = (l + r) / 2;
    if(S(mid) < kth) l = mid;
    else r = mid;
  }
  return r;
}

int solve(int k, int i, int n){
  int ind = bin_search(k);
  U(ind, -1);
  ord[i] = ind;
  if(!n) return 0;
  k += -1 + card[ind];
  if(card[ind] > 0) k--;
  if(k < 0) k = (int)mod(k, n);
  k %= n;
  k++;
  return k;
}

int main(){
	for(int i = 1; i<max_v; i++){
    for(int j = 1; i * j < max_v; j++){
      fac[i * j]++;
    }
  }
  int n, k;
  while(scanf("%d%d", &n, &k) == 2){
    memset(BIT, 0, sizeof(BIT));
    memset(card, 0, sizeof(card));
    memset(ord, 0, sizeof(ord));
    N = n;
    for(int i = 1; i<=n; i++) scanf("%s%d", str[i], &card[i]);
    for(int i = 1; i<=n; i++) U(i, 1);
    
    for(int i = 1; i<=n; i++){
      //printf("%d ", k);
      k = solve(k, i, n - i);
    }
    //puts(""); 
    int maxi = -1, max_ind = 0;
    for(int i = 1; i<=n; i++){
      
      if(fac[i] > maxi){
        maxi = fac[i];
        max_ind = ord[i];
      }
    }
    assert(maxi > 0 && max_ind);
    printf("%s %d\n", str[max_ind], maxi);

  }

	return 0;
}

