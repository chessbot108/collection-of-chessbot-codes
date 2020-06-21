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
#define LOGN (50)
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) | 1)
#define RC(n) (((n) << 1) + 2)
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int root[max_v];

struct node{
  long long sum = 0, add = 0, set_tag = 0;
  bool marked = false;
  int lc = 0, rc = 0;
  node(){}
  node(long long a, long long b, long long c, bool d, int e, int f){
    sum = a, add = b, set_tag = c, marked = d, lc = e, rc = f;
  }
  node(long long a, int l, int r){
    sum = a, lc = l, rc = r;
  }
  
  node &operator= (const node& b){
    sum = b.sum;
    add = b.add;
    set_tag  = b.set_tag;
    marked = b.marked;
    lc = b.lc;
    rc = b.rc;
    return *this;
  }
  void clear_tag(){
    set_tag = 0, add = 0, marked = false;
  }

} nodes[max_v * LOGN];

int n, s, ind;
long long arr[max_v];

void dup(int& k){
  nodes[++ind] = nodes[k];
  k = ind;
}


void tag(bool marked, long long set_tag, long long add, int& K, int len){
  dup(K);
  node& k = nodes[K];
  if(marked){
    k.set_tag = set_tag;
    k.marked = true;
    k.sum = (long long)len * k.set_tag;
  }else{
    k.add += add;
    k.sum += (long long)len * add;
  }
}

void push_down(int& k, int L, int R){
  if(L + 1 == R ) return ;
  tag(nodes[k].marked, nodes[k].set_tag, nodes[k].add, nodes[k].lc, (R - L) / 2);
  tag(nodes[k].marked, nodes[k].set_tag, nodes[k].add, nodes[k].rc, (R - L) / 2);
  nodes[k].clear_tag();
}


void U(int qL, int qR, int& k, bool m, long long a, long long b, int L, int R){
  if(R <= L || qR <= L || R <= qL) return ;
  if(qL <= L && R <= qR){
    tag(m, a, b, k, R - L);
    return ;
  }
  dup(k);
  int mid = (L + R) / 2;
  if(nodes[k].marked)
    push_down(k, L, R);
  U(qL, qR, nodes[k].lc, m, a, b, L, mid);
  U(qL, qR, nodes[k].rc, m, a, b, mid, R);
  nodes[k].sum = nodes[nodes[k].lc].sum + nodes[nodes[k].rc].sum;
}

long long S(int qL, int qR, int& k, int L, int R){
  if(R <= L || qR <= L || R <= qL) return 0ll;
  if(qL <= L && R <= qR) return nodes[k].sum;
  
  int mid = (L + R) / 2;
  if(nodes[k].marked){
    dup(k);
    push_down(k, L, R);
  }
  return S(qL, qR, nodes[k].lc, L, mid) + S(qL, qR, nodes[k].rc, mid, R);
}

int main(){
  int q;
  scanf("%d%d", &n, &q);
  s = pow_2((int)(ceil(log2(n))));
  ind = s * 2;
  root[0] = 0;

  for(int i = 0; i<n; i++)
    scanf("%lld", &arr[i]);
    
  for(int i = 0; i<n; i++)
    nodes[i + (s - 1)] = node(arr[i], 0, 0);  

  for(int i = s - 2; i >= 0; i--)
    nodes[i] = node(nodes[LC(i)].sum + nodes[RC(i)].sum, LC(i), RC(i));
  
  
  for(int i = 1; i<=q; i++){
    printf("query #%d\n", i);
    int op, t;
    scanf("%d%d", &op, &t);
    root[i] = root[t];
    if(op == 1){ //query
      int a, b;
      scanf("%d%d", &a, &b);
      printf("%lld\n", S(a - 1, b, root[i], 0, s)); 
    }else if(op == 2){ //add
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      U(a - 1, b, root[i], false, 0ll, c, 0, s);
    }else if(op == 3){ //set
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      U(a - 1, b, root[i], true, c, 0ll, 0, s);
    }else if(op <= 0){
      break;
    }
  }



	return 0;
}

