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
#include <unordered_map>
//#include <unordered_set>
#include <functional>

#define max_v 41000
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


int parent[max_v]; //the node i's parity depends on
int parity[max_v]; //the partity of node i
unordered_map<int, int> disc;
int inc = 1;
/**
 * freaking DSU
 * parity[l - 1] ^ parity[r] = parity of the range
 *
 * and since 1e4 queries, discretation is needed
**/

int getID(int x){
  //fake hashing
  if(disc.count(x)) return disc[x];
  disc[x] = inc++;
  return disc[x];
} 

int find(int x){
  if(x != parent[x]){
    int temp = find(parent[x]); //new parent for x
    parity[x] ^= parity[parent[x]]; //xor'ing the current x by the new parent's parity
    parent[x] = temp; //path compression
  }
  return parent[x];
} 

int main(){
	int n, m;
  scanf("%d%d", &n, &m);
  int ans = m;
  for(int i = 0; i<=m*4; i++) parent[i] = i; //m*4 should be safe, right?
  for(int i = 0; i<m; i++){
    int l, r;
    char str[10];
    scanf("%d%d%s", &l, &r, str);
    int t = (str[0] == 'e') ? 0 : 1;
    
    l = getID(l - 1), r = getID(r);
    
    int par_l = find(l), par_r = find(r);

    if(par_l == par_r){ //they depend on the same node
      if(parity[l] ^ parity[r] != t){ //the xor of their parity does not match the query AND they depend on the same person, so nothing else should matter
        ans = i; //then the query is illegal
        break;
      }
    }else{ //prefectly safe. nothing that matters across the 2 nodes. 
      //must Union them since there is a new condition now
      parent[par_l] = par_r;
      parity[par_l] ^= parity[l] ^ parity[r] ^ t; //the new parity for par_l must match, no changes needed for parity[par_r] 
    }
  }

  printf("%d\n", ans);


  return 0;
}

