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

#define max_v 11000
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

#define v first
#define w second
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

struct node{
  long long key, dist;
  node(){}
  node(int a, int b){key = a, dist = b;}
  bool operator < (const node&b) const{
    return dist > b.dist;
  }

};


list<pair<long long, long long> > adj[max_v];
long long arr[max_v], dist[max_v], cows[max_v], pre[max_v];
bool vis[max_v];

long long n, m, T;

priority_queue<node> pq;
list<long long> st;
void dijkstra(){
  memset(dist, 0x3f, sizeof(dist));
  dist[1] = 0ll;

  pq.push(node(1ll, 0ll));

  while(!pq.empty()){
    node top = pq.top(); pq.pop();
    long long u = top.key;
    if(vis[u]) cont;
    vis[u] = true;
    st.push_front(u);

    for(auto E : adj[u]){
      long long temp = dist[u] + E.w;
      if(dist[E.v] > temp){
        pre[E.v] = u;
        dist[E.v] = temp;
        pq.push(node(E.v, dist[E.v]));
      }else if(dist[E.v] == temp){
        pre[E.v] = min(pre[E.v], u);
      }
    }
    
  }
  
}

void print(int cur){
  if(cur == 0ll) return ;
  print(pre[cur]);
  printf("%d  ", cur);
}


int main(){
  setIO("shortcut"); //submitted on usaco to assert it was correct
	scanf("%lld%lld%lld", &n, &m, &T);
  for(int i = 1; i<=n; i++){
    scanf("%lld", &arr[i]);
  }
    
  for(int i = 1; i<=m; i++){
    int a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    adj[a].push_back(make_pair(b, c));
    adj[b].push_back(make_pair(a, c));
  }

  dijkstra();
  
  while(!st.empty()){
    int u = st.front(); st.pop_front();
    cows[u] += arr[u];
    cows[pre[u]] += cows[u]; 
  }

  long long ans = 0;
  for(int i = 2; i<=n; i++){
    ans = min(ans, (long long)cows[i] * (T - dist[i]));
  }
  printf("%lld\n", -ans);
  /**
  for(int i = 1; i<=n; i++){
    printf("%d, %d %d\n", i, dist[i], cows[i]);
    print(i);
    puts("");
  }
  **/
	return 0;
}

