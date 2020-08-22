//code by me. ddin't finish during the contest tho :sob:
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

#define max_v 1100
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
const long long mod = (long long) 1e9 + 7;
bool graph[30][30]; //too lazy, n is 20 :/
bool useful[30];
long long face[30], fact[30];
long long ways[30]; //ways to knapsack element i
long long paths[30]; //reach, the multi of all the children's knapsack
int bitm[max_v];
int n, m;
void dfs(int a, int pa){
  useful[a] = true;
  for(int i = 1; i<=n; i++){
    if(graph[i][a] && i != pa) dfs(i, a);
  }
}


long long binpow(long long a, long long b) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void comp(){
  fact[0] = 1;
  for(int i = 1; i<=n; i++){
    fact[i] = (fact[i - 1] * (long long)i) % mod;
  } 
}


long long knapsack(int ind){
  int B = bitm[ind] | pow_2(ind);
  long long ans = 0;
  int last = 0, cnt = 0;

  for(int i = 1; i<=ind; i++){
    if(B & pow_2(i)){
      long long tmp = face[i] / face[last];
      ans = binpow(ans, tmp)/fact[cnt] +1;
      last = i;
      cnt++;
    }
  }
  return ans;
}




int main(){
  face[0] = 1ll;
  scanf("%d%d", &n, &m);
  comp(); 
  for(int i = 1; i<=n; i++){
    scanf("%lld", &face[i]);
  }
  for(int i = 0; i<m; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    graph[a][b] = true;
    bitm[b] |= pow_2(a);
  }
  
  dfs(n, -1);
  for(int i = 1; i<=n; i++){
    //printf("%d -> %d\c\n", i, (int) useful[i]);
    if(!useful[i]){
      for(int j = 1; j<=n; j++){
        bitm[i] -= pow_2(j);
      }
    }
  }
  for(int i = 1; i<=n; i++){
    ways[i] = knapsack(i);
    //printf("%d\n", ways[i]);
  }
  
  for(int i = 1; i<=n; i++){
    paths[i] = 1;
    for(int j = 1; j<=n; j++){
      if(graph[j][i]){
        paths[i] = (paths[i] * ways[j]) % mod;
      }
    }
    //printf("%d %d\n", i, paths[i]);
  }
  printf("%lld\n", paths[n] + ways[n]);
	return 0;
}

