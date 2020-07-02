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

#define max_v 1100
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)

using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int par[max_v], child[max_v];

void dfs(int cur){
  if(!cur) return;
  child[cur]++;
  dfs(par[cur]);
}

int main(){
	
  int n;
  scanf("%d", &n);

  for(int i = 2; i<=n; i++){
    int a;
    scanf("%d", &a);
    par[i] = a;
  }
  
  for(int i = 1; i<=n; i++){
    dfs(i);
  }
  
  for(int i = 1; i<=n; i++){
    printf("%d ", child[i]);
  } 


	return 0;
}

