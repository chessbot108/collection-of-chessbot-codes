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

class trie{
  char key[max_v];
  int child[max_v], brother[max_v], parent[max_v], value[max_v];
  int size;
  public:
    trie(){
      memset(child, 0, sizeof(child));
      memset(brother, 0, sizeof(brother));
      memset(parent, 0, sizeof(parent));
      memset(value, 0, sizeof(parent));
      memset(key, '\0', sizeof(key));
      size = 0;
    }
    
    void insert(char* s, int n){
      int u = 0;
      for(int i = 0; i<n; i++){
        bool found = false;
        for(int j = child[u]; j; j = brother[j]){
          if(key[j] == s[i]){
            u = j;
            found = true;
            break;
          }
        }
        
        if(!found){
          size++;
          key[size] = s[i];
          brother[size] = child[u];
          child[u] = size;
          parent[size] = u;
          child[size] = 0;
          u = size;
        }

      }
      value[u]++;

    }
    
    int count(char* s, int n){
      int u = 0;
      printf("query for: %s\n", s);
      for(int i = 0; i<n; i++){
        bool found = false;
        for(int j = child[u]; j; j = brother[j]){
          if(key[j] == s[i]){
            found = true;
            u = j;
          }
        }
        if(!found) return 0;
      }
      return value[u];
    }
    
    void print_all(){
      for(int i = 0; i<=size; i++){
        printf("key %c (index %d):\n\tparent: %d\n\tchild: %d\n\tbro: %d\n\tvalue: %d\n", key[i], i, parent[i], child[i], brother[i], value[i]);
      }

    }

};

char str[max_v];

int main(){
	int com;
  trie T;
  while(scanf("%d", &com)){
    if(com <= 0) break;
    if(com == 1){
      scanf("%s", str);
      int n = strlen(str);
      T.insert(str, n);
    }else if(com == 2){
      scanf("%s", str);
      int n = strlen(str);
      printf("%d\n", T.count(str, n));
    }else if(com == 3){
      T.print_all();
    }
  }
	return 0;
}

