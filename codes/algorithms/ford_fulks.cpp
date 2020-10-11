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

#define max_v 4000
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

long long adj[max_v][max_v], flow[max_v][max_v]; //i think that E isn't part of the complexity so this is good. also doubling nodes
bool vis[max_v];
int n, m;


long long send(int s, long long mini){ //credits to juanplopes for this amazing code
    vis[s] = true;
    if(s == n) return mini; //found final
    long long flo = 0;
    for(int i = 1; i<=n; i++){
      long long cap = adj[s][i] - flow[s][i]; //flow for this edge
      if(!vis[i] && cap > 0){ //legal edge
        int sent = send(i, min(mini, cap)); //backtrack to find min amount.
        if(sent){ //max flow is 0
          flo += sent;
          flow[s][i] += sent; //augment
          flow[i][s] -= sent; //augment
          mini = min(mini, adj[s][i] - flow[s][i]);
        }
      }
    }
    return flo; //nothing sent out
}


int main(){
	scanf("%d%d", &n, &m);
  while(m--){
    long long a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    adj[a][b] += c;
    adj[b][a] += c;
  }

  long long F = 0ll;
  for(;;){
    long long sent = send(1, (long long)int_max);
    if(!sent) break;
    F += sent;
    memset(vis, 0, sizeof(vis));
  }

  printf("%lld\n", F);


	return 0;
}

