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
#include <unordered_set>
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

list<int> adj[max_v];
int ans[max_v], arr[max_v];
bool vis[max_v];
int n;
multiset<int> buckets;

void dfs(int u){
  if(vis[u]) return;
  vis[u] = true;
  for(auto it = adj[u].begin(); it != adj[u].end();){
    if(vis[*it]) it = adj[u].erase(it);
    else {dfs(*it); it++;} //rooting tree and removed dup edges
  }
}

bool solve(int u, int k){
  

  bool res = true;
  for(int x : adj[u]) res &= solve(x, k);
  //dnq go brrrrrrr
  if(!res) return false;
  buckets.clear();
  
  ans[u] = 0;
  for(int x : adj[u]){
    if(ans[x] % k == 0) cont; 
    if(buckets.count(k - ans[x])){
      buckets.erase(buckets.find(k - ans[x]));
    }else{
      buckets.insert(ans[x]);
    }
  }
  if(buckets.size() > 1) return false;
  ans[u] = buckets.empty() ? 0 : *(buckets.begin());
  ans[u] = (ans[u] + 1) % k; //include path form this node to the parent
  return true;
}

int main(){
  //setIO("deleg");
  scanf("%d", &n);
  for(int i = 1; i<n; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1);

  printf("1");
  for(int i = 2; i<=n - 1; i++){
    if((n - 1) % i == 0) printf("%d", (int)solve(1, i));
    else printf("0");
  }
  

	return 0;
}

