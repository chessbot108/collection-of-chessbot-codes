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
#include <queue>

#define max_v 3100
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)
using namespace std;

struct query{
  int Q_num;
  int period;
  
  query(int a, int b){
    period = a; Q_num = b;
  }
  
  bool operator < (const query& b) const{
    return period > b.period || (period == b.period && Q_num > b.Q_num);
  }
};
priority_queue<query> pq;
char str[max_v];
int get_per[max_v];

int main(){
	
  //freopen("a.in", "r", stdin);
  //freopen("a.out", "w+", stdout);

  while(scanf("%s", str) == 1){
    if(str[0] == '#') break;
    int a, b;
    scanf("%d%d", &a, &b);
    get_per[a] = b;
    pq.push(query(b, a));
  }

  int k;
  scanf("%d", &k);
  
  while(k--){
    query cur = pq.top(); pq.pop();
    printf("%d\n", cur.Q_num);
    pq.push(query(cur.period + get_per[cur.Q_num], cur.Q_num));
  }


	return 0;
}

