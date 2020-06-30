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
#include <exception>
#include <deque>

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

int dig[max_v];
char str[max_v];
bool del[max_v];
int n, m;

int main(){
  while(~scanf("%s %d", str, &m)){
    memset(dig, 0, sizeof(dig));
    memset(del, 0, sizeof(del));
    n = strlen(str);
  
    for(int i = 0; i<n; i++)
      dig[i] = str[i] - '0';

    dig[n] = -1;
      
    if(n == m){
      printf("0\n");
      cont;
    }

    assert(m <= n);
    deque<int> d;
    d.push_back(dig[0]);

    int cnt = 0, ind = 1, i;
    //assert(false);
    while(ind <= n){
      i = ind;
      while(m && !d.empty() && dig[ind] < d.back()){
        d.pop_back();
        m--;
      }
      d.push_back(dig[ind]);
      ind++;
    }
    
    //assert(false);
    
    bool b = false;

    for(int i = 0; i<d.size() - 1; i++){
      if(d[i]) b = true;
      if(b) printf("%d", d[i]);
    }

    if(!b) printf("0");

    puts("");

  }
	return 0;
}

