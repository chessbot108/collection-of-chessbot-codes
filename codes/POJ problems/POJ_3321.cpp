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

#define max_v 110000
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)
#define lsb(n) ((n)&(-(n)))
#define init(arr) memset(arr, 0 , sizeof(arr))
#define v first
#define nxt second

using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}


int l[max_v], r[max_v], BIT[max_v], s[max_v], ind[max_v];
int n, q, lab = 0, nu = 1;
//all 1-based
pair<int, int> edges[max_v * 2];
void add(int u, int v){
  edges[nu] =  make_pair(v, ind[u]);
  ind[u] = nu++;
  edges[nu] =  make_pair(u, ind[v]);
  ind[v] = nu++;
}


int Q(int i){
  if(!i) return 0;
  return BIT[i] + Q(i - lsb(i));
}

void U(int i, int val){
  if(i > n) return ;
  BIT[i] += val;
  U(i + lsb(i), val);
}
 
void dfs(int par, int cur){
  l[cur] = ++lab;
  for(int i = ind[cur]; i != 0; i = edges[i].nxt){
    if(edges[i].v != par) dfs(cur, edges[i].v);
  }
  r[cur] = lab;
}


int main(){
  //edges.push_back(make_pair(0, 0));
  scanf("%d", &n);

  for(int i = 0; i < n - 1; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b);
  }
  
  dfs(0, 1);

  for(int i = 1; i <= n; i++){
    U(l[i], 1);
    s[l[i]] = 1;
  }
  
  scanf("%d", &q);

  while(q--){
    char str[10];
    int a;
    scanf("%s %d", str, &a);

    if(str[0] == 'Q'){
      printf("%d\n", Q(r[a]) - Q(l[a] - 1));
    }else{
      if(s[l[a]] == 1) U(l[a], -1);
      else U(l[a], 1);
      s[l[a]] = 1 - s[l[a]];
    }
  


  }

  




  return 0;
}


