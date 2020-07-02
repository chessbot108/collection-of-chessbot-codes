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

#define max_v 1100000
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)
#define lsb(n) ((n) & (-(n)))
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int rate[max_v];
int lab = 0, n;
list<int> arr[max_v];
int srt[max_v], BIT[max_v];
int L[max_v], R[max_v];


int get_ind(int key){
  return lower_bound(srt + 1, srt + n + 1, key) - &srt[0]; 
}

int S(int i){
  if(!i) return 0;
  return BIT[i] + S(i - lsb(i));
}

void U(int i, int val){
  if(i > n) return;
  BIT[i] += val;
  U(i + lsb(i), val);
}

void dfs(int cur){
  L[cur] = S(get_ind(rate[cur]));
  for(int ch : arr[cur]){
    dfs(ch);
  }
  R[cur] = S(get_ind(rate[cur]));
  U(get_ind(rate[cur]), 1);
}

int main(){
  setIO("promote");
  scanf("%d", &n);
  
  for(int i = 1; i<=n; i++){
    scanf("%d", &rate[i]);
    rate[i] = (int)1e9 - rate[i];
    srt[i] = rate[i];
  }

  sort(srt + 1, srt + n + 1);
  
  for(int i = 2; i<=n; i++){
    int par;
    scanf("%d", &par);
    arr[par].push_back(i);
  }
  
  dfs(1);

  for(int i = 1; i<=n; i++){
    printf("%d\n", R[i] - L[i]);
  }

  


	return 0;
}

