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
#include <stack>
#include <queue>
//#include <unordered_map>
//#include <unordered_set>
#include <functional>

#define max_v 1100
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)
#define lsb(n) ((n)&(-(n)))

using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

bool vis[max_v];
map<int, pair<int, int>> tree;
int n;

void pre(){
  memset(vis, 0, sizeof(vis));
  stack<int> s;
  s.push(1);
  while(!s.empty()){
    int cur = s.top(); s.pop();
    if(vis[cur]){if(cur) printf("%d ", cur); cont;}
    vis[cur] = true;
    s.push(tree[cur].second);
    s.push(tree[cur].first);
    s.push(cur);
  }
  puts("");
}


void in(){
  memset(vis, 0, sizeof(vis));
  stack<int> s;
  s.push(1);
  while(!s.empty()){
    int cur = s.top(); s.pop();
    if(vis[cur]){if(cur) printf("%d ", cur); cont;}
    vis[cur] = true;
    s.push(tree[cur].second);
    s.push(cur);
    s.push(tree[cur].first);
  }
  puts("");
}

void post(){
  memset(vis, 0, sizeof(vis));
  stack<int> s;
  s.push(1);
  while(!s.empty()){
    int cur = s.top(); s.pop();
    if(vis[cur]){if(cur) printf("%d ", cur); cont;}
    vis[cur] = true;
    s.push(cur);
    s.push(tree[cur].second);
    s.push(tree[cur].first);
  }
  puts("");
}



int main(){
  scanf("%d", &n);

  for(int i = 0; i<n; i++){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    tree.insert(make_pair(a, make_pair(b, c)));
  }
  
  pre();
  in();
  post();
  
  
	return 0;
}

