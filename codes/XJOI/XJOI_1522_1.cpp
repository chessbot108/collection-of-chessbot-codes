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

struct node{
  int key;
  long long value;
  node(){}
  node(int a, long long b){
    key = a, value = b;
  } 
  bool operator < (const node& b) const{
    return value > b.value;
  }
};

list<pair<int, long long> > arr[max_v];
int n, m;
bool vis[max_v];
long long dist[max_v];
priority_queue<node> pq;

long long prim(){
  long long ans = 0;
  memset(dist, 0x3fll, sizeof(dist));
  dist[1] = 0ll;
  pq.push(node(1, 0ll));
  while(!pq.empty()){
    node cur = pq.top(); pq.pop();
    int key = cur.key; 
    if(vis[key]) cont;
    vis[key] = true;
    ans += dist[key];

    for(auto i : arr[key]){
      if(dist[i.first] > i.second){
        dist[i.first] = i.second;
        pq.push(node(i.first, dist[i.first]));
      }
    }
    
  }
  return ans;
}



int main(){
	scanf("%d%d", &n, &m);
  for(int i = 0; i<m; i++){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    arr[a].push_back(make_pair(b, (long long)c));
    arr[b].push_back(make_pair(a, (long long)c));
  }
  printf("%lld\n", prim());
	return 0;
}

