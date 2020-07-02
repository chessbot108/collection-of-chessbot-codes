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

#define max_v 410000
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << (n))
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) | 1)
#define RC(n) (((n) << 1) + 2)
#define LOG2(n) ((int)(ceil(log2((n)))))
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int count_bits(int a){
  if(!a) return 0;
  return 1 + count_bits(a - lsb(a));
}

int colors[max_v], set_tag[max_v], s, n;
bool marked[max_v];

void push_down(int k, int L, int R){
  if(!marked[k] || L + 1 == R) return; //no tag, nothing farther down
  set_tag[LC(k)] = set_tag[RC(k)] = set_tag[k];
  marked[LC(k)] = marked[RC(k)] = true;
  colors[LC(k)] = set_tag[k];
  colors[RC(k)] = set_tag[k];
  set_tag[k] = 0;
  marked[k] = false;
}

void update(int k){
  colors[k] = (colors[LC(k)] | colors[RC(k)]);
}


void U(int qL, int qR, int k, int val, int L, int R){
  if(R <= L || qR <= L || R <= qL) return ;
  if (qL <= L && R <= qR){
    set_tag[k] = val;
    marked[k] = true;
    colors[k] = val;
    return ;
  }
  int mid = (L + R) / 2;
  push_down(k, L, R);
  U(qL, qR, LC(k), val, L, mid);
  U(qL, qR, RC(k), val, mid, R);
  update(k);
}

int S(int qL, int qR, int k, int L, int R){
  if(R <= L || qR <= L || R <= qL) return 0;
  if(qL <= L && R <= qR) return colors[k];
  int mid = (L + R) / 2;
  push_down(k, L, R);
  return (S(qL, qR, LC(k), L, mid) | S(qL, qR, RC(k), mid, R));
}



int main(){
	int q, t;
  scanf("%d%d%d", &n, &t, &q);
  s = pow_2(LOG2(n + 1));
  U(0, n, 0, pow_2(1), 0, s);
  while(q--){
    char com[10];
    scanf("%s", com);
    if(com[0] == 'C'){
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      if(a > b) swap(a, b);
      U(a - 1, b, 0, pow_2(c), 0, s);
    }else{
      int a, b;
      scanf("%d%d", &a, &b);
      if(a > b) swap(a, b); //f**king scam
      int ans = S(a - 1, b, 0, 0, s);
      printf("%d\n", count_bits(ans));
    }
  }
	return 0;
}

