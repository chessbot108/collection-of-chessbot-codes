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

#define max_v 51000
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
//TLE sol. i figured out the AC one but it's literally impossible to impl. eternal agony

int n;
int arr[max_v][10];

bool comp(int a, int b){
  //printf("%d %d\n", a, b); 
  for(int i = 0; i<5; i++) 
    for(int j = 0; j<5; j++)
      if(arr[a][i] == arr[b][j]) return true;
  return false;
}


int main(){
	int ans = 0;
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    for(int j = 0; j<5; j++) scanf("%d", &arr[i][j]);
    for(int j = 0; j<i; j++) if(comp(i, j)) ans++;
  }
  printf("%d\n", ((n * (n - 1)))/2 - ans);
	return 0;
}

