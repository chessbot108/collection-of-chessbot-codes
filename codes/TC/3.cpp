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

int step[max_v];
bool vis[max_v];
int cnt = 0, n;

int main(){
	cin >> n;
  for(int i = 0; i<n; i++){
    cin >> step[i];
  }
  int start  = 0;
  while(true){
    if(step[start] == 0 || vis[start]){ break; }

    vis[start] = true;
    start = (start + step[start]) % n;
    cnt++;
    
  }
  if(vis[start]) cout << "-1";
  else cout << cnt;
	return 0;
}

