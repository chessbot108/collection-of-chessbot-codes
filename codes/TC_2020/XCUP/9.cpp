//code by me

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

#define max_v 22000
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


vector<int> adj[max_v];
int ans[max_v], sum[max_v];
int n;


int dfs(int cur, int p){
  
  for(int u : adj[cur]){
    if(u == p) cont;
    int temp = dfs(u, cur);
    if(temp > n/2) ans[cur] = true;
    sum[cur] += temp;
  }
  sum[cur]++;
  if(n - sum[cur] > n/2) ans[cur] = true;
  return sum[cur];
}



int main(){
	
  scanf("%d", &n);
  for(int i = 1; i<n; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  } 
  dfs(1, 0);
  for(int i = 1;i <=n; i++){
    if(!ans[i]) printf("%d\n", i);
  }
	return 0;
}

