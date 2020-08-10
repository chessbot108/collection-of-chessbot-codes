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

#define max_v 1100
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
  int key, dist;
  node(){}
  node(int a, int b){ key = a, dist = b; }
  bool operator < (const node& b) const{
    return dist > b.dist;
  }
};


list<pair<int, int> > arr[max_v];

priority_queue<node> pq;
int dist[max_v], n, m;



int main(){
  scanf("%d%d" &n, &m);
  for(int i = 0; i<m; i++){
    int a, b, c; //u, v, weight
    scanf("%d%d%d", &a, &b, &c);
    arr[a].push_back(make_pair(b, c));
    arr[b].push_back(make_pair(a, c));
  }
	return 0;
}

