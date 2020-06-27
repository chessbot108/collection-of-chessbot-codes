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

int ans[max_v], arr[max_v], t[max_v], n;
bool vis[max_v];

int check(int k){
  if(ans[k]) return ans[k];
  int cnt = 0, cur = 0;

  for(int i = 0; i<n; i++){
    if(!vis[arr[i]]){
      t[cur++] = arr[i];
      vis[arr[i]] = true;
    }
    if(cur == k){
      cnt++;
      for(int j = 0; j<k; j++){
        vis[t[j]] = false;
        t[j] = 0;
      }
      cur = 0;
    }
  }
  if(cur) cnt++;
  return cnt;
}

void dnq(int L, int R){
  //printf("%d %d", L, R);
  assert(L <= R);
  ans[L] = check(L);
  ans[R] = check(R);
  if(ans[L] == ans[R]){
    for(int i = L; i<=R; i++){
      ans[i] = ans[L];
    }
    return ;
  }else{
    int mid = (L + R) / 2;
    
    dnq(L, mid);
    dnq(mid + 1, R);
  }
  return ;
}

int main(){
	
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  //assert(false);
  dnq(1, n);
  
  for(int i = 1; i<=n; i++){
    printf("%d ", ans[i]);
  }

	return 0;
}

