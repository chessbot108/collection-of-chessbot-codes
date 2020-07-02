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
//#include <unordered_map>
//#include <unordered_set>
#include <functional>
#include <queue>

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

struct node{
  int key, index, x;
  node(int a, int b, int c){
    key = a, index = b, x = c;
  }

  bool operator < (const node& b) const{
    return key > b.key;
  }
};


vector<pair<int, pair<int, int>>> eq;
priority_queue<node> pq;

int val(int i, int x){
  int a = eq[i].first;
  int b = eq[i].second.first;
  int c = eq[i].second.second;
  return (a*x*x) + (b*x) + c;
}


int main(){
	int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 0; i<n; i++){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    eq.push_back(make_pair(a, make_pair(b, c)));
    pq.push(node(val(i, 1), i, 1));
  }
  
  while(m--){
    node cur = pq.top(); pq.pop();
    int i = cur.index, key = cur.key, x = cur.x;
    printf("%d ", key);
    pq.push(node(val(i, x + 1), i, x + 1));
  }


	return 0;
}

