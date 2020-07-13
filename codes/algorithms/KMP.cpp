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

int pi[max_v];
char str[max_v], pat[max_v];
bool start[max_v];
int n, m;

void shift(int n, char s[]){
  for(int i = n; i; i--){
    s[i] = s[i - 1];
  }
  s[0] = 0;
}

void precomp(){
  pi[0] = -1;
  int k = 0;
  for(int i = 1; i<=m; i++){
    k = i - 1;
    while(k >= 0 && pat[k + 1] != pat[i]){
      k = pi[k];
    }
    pi[i] = ++k;
    printf("%d\n", pi[i]);
  }

}


int main(){
  scanf("%s%s", str, pat);
  n = strlen(str);
  m = strlen(pat);
  shift(n, str);
  shift(m, pat);
  precomp();
  return 0;
}
