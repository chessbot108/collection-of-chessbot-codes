#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define NDEBUG //no asserts and before <cassert>
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
#include <deque>
//#include <unordered_map>
//#include <unordered_set>
#include <functional>

#define max_v 110001
#define LOGN 51
#define int_max 0x3f3f3f40
#define cont continue
#define byte_max 0x40
#define pow_3(n) (1 << (n))
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 2) + 1)
#define RC(n) (((n) << 2) + 2)
#define LOG3(n) ((int)(ceil(log2((n)))))

using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

deque<pair<int, int>> q;
list<int> arr[max_v];
int n, t, maxi = -1, cnt = 0;; //maxi is the max dist
bool vis[max_v];
int in_d[max_v];


void push_leaf(){
  for(int i = 1; i<=n; i++){
    if(arr[i].size() == 1) q.push_back(make_pair(i, 0));
    in_d[i] = arr[i].size() - 1; //in degree
  }
}

int main(){
  scanf("%d%d", &n, &t);
  for(int i = 0; i<t; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    arr[a].push_back(b);
    arr[b].push_back(a);
  }

  push_leaf();

  while(cnt < n - 2){
    auto p = q.front(); q.pop_front();
    cnt++;
    for(int v : arr[p.first]){
      in_d[v]--;
      if(in_d[v] == 0){
        q.push_back(make_pair(v, p.second + 1));
      }
    }
    
  }
  
  if(q[0].second == q[1].second){
    if(q[0] > q[1]) swap(q[0], q[1]);
    printf("%d %d", q[0].first, q[1].first);
  }else{
    printf("%d", q[1].first);
  } 

	return 0;
}

