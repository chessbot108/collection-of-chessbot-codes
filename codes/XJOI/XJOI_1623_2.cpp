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
const int mod = 1e5;

long long dist[max_v], vis[max_v];
long long edge(int a, int b){
  if(a > b) swap(a, b);
  long long A = a * 2019201913ll;
  long long B = b * 2019201949ll;
  return (A + B) % 2019201997ll;
}

void prim(int n, int k){
  for(int i = 0; i<=n; i++) dist[i] = 20192020000ll; //intmax be like
  dist[1] = 0ll;
  while(true){
    int ind = 0;
    for(int i = 1; i<=n; i++){
      if(dist[i] < dist[ind] || ind == 0){
        if(vis[i]) cont;
        ind = i;
      }
    }
    if(ind == 0) break;
    vis[ind] = true;
    for(int i = 1; i<=n; i++){
      if(i != ind && !vis[i]) dist[i] = min(edge(i, ind), dist[i]);
      //printf("%d %d %d %d \n", i, ind, edge(i, ind), dist[i]);
    }
  }
  sort(dist + 1, dist + n + 1, greater<long long>());
  //for(int i = 0; i<=n; i++) printf("%d\n", dist[i]);
  printf("%lld\n", dist[k - 1]);
}


int main(){
  int n, k;
  scanf("%d%d", &n, &k);
  prim(n, k); 
	return 0;
}

