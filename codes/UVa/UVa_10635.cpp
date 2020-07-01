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
#include <unordered_map>
#include <unordered_set>
#include <functional>

#define max_v 63000
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)

using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int p[max_v], q[max_v], ind[max_v], overlap[max_v];

int LIS(int* arr, int n){
  set<int> s;

  for(int i = 0; i<n; i++){
    if((s.insert(arr[i])).second){
      auto it = s.find(arr[i]);
      it++;
      if(it != s.end()) s.erase(it);
    }
  }
  return s.size();
}


int main(){
  int T, kase = 0;
  scanf("%d", &T);
  while(T--){
    int n, P, Q;
    scanf("%d%d%d", &n, &P, &Q);
    
    memset(p, 0, sizeof(p));
    memset(q, 0, sizeof(q));
    memset(ind, 0x8f, sizeof(ind));
    memset(overlap, 0x8f, sizeof(overlap));

    for(int i = 0; i < P; i++)
      scanf("%d", &p[i]);

 
    for(int i = 0; i < Q; i++)
      scanf("%d", &q[i]);

    for(int i = 0; i<P; i++)
      ind[p[i]] = i;
    
    for(int i = 0; i<Q; i++)
      overlap[i] = ind[q[i]];
    
    printf("Case %d : %d\n", ++kase, LIS(overlap, Q));
    
  }
  
	return 0;
}

