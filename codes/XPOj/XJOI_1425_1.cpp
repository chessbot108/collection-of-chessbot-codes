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

map<int, pair<int ,int>> tree;
map<int, int> par;

void pre(int a){
  if(a == 0 || tree.count(a) == 0) return;
  printf("%d ", a);
  pre(tree[a].first);
  pre(tree[a].second);
}

void post(int a){
  if(a == 0 || tree.count(a) == 0) return;
  post(tree[a].first);
  post(tree[a].second);
  printf("%d ", a);
}


void in(int a){
  if(a == 0 || tree.count(a) == 0) return;
  in(tree[a].first);
  printf("%d ", a);
  in(tree[a].second);
}

int main(){
	int n, sam;
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    tree.insert(make_pair(a, make_pair(b, c)));
    if(b) par.insert(make_pair(b, a));
    if(c) par.insert(make_pair(c, a));
    sam = a;
  }
  
  while(par.count(sam)) sam = par[sam];
  
  pre(sam);
  puts("");
  in(sam);
  puts("");
  post(sam);
  puts("");

	return 0;
}

