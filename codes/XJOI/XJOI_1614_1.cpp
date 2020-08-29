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
#define v second
#define w first
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

list<pair<int, int> > adj[max_v]; //REMEMBER WEIGHT IS .FIRST!!!
int ans[max_v], arr[max_v], vis[max_v], par[max_v];
int n, m, C;
list<int> srt, q;

void bfs(){
  for(int i = 1; i<=n; i++){
    if(par[i] == 0) q.push_back(i);
  }
  while(!q.empty()){
    int top = q.front(); q.pop_front();
    srt.push_back(top);
    for(const auto& p : adj[top]){
      par[p.second]--;
      if(!par[p.second]) q.push_back(p.second);
    }   
  }
}



int main(){
	scanf("%d%d%d", &n, &m, &C);
  for(int i = 1; i<=n; i++){
    scanf("%d", &arr[i]);
  }
  for(int i = 0; i<C; i++){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    par[b]++;
    adj[a].push_back(make_pair(c, b));
  }
  
  for(int i = 1; i<=n; i++){
    adj[i].sort();
    //printf("%d, (%d):\n", i, par[i]);
    //for(const auto&p : adj[i]) printf("\t->%d, %d\n", p.second, p.first); puts("");
  }
  bfs();
  //for(int x : srt) printf("%d ", x); puts("");
  
  for(int x : srt){
    ans[x] = max(ans[x], arr[x]);
    for(const auto& p : adj[x]){
      ans[p.second] = max(ans[p.second], ans[x] + p.first);
    }
  }

  for(int i = 1; i<=n; i++) printf("%d\n", ans[i]);

	return 0;
}

