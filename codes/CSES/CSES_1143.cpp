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

#define max_v 210000
#define ROOTN 500
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

int arr[max_v], n, q;
int maxi[ROOTN];
int hotels[ROOTN][ROOTN];

int Q(int k){
  int ind = -1;
  for(int i = 0; i<=n/ROOTN; i++){
    if(maxi[i] >= k){ ind = i; break; }
  }

  if(ind == -1) return 0;

  for(int i = 0; i<ROOTN; i++){
    if(hotels[ind][i] >= k) return ind * ROOTN + i + 1;
  }
  return 0; //should not happen but a return value is there for safety
}

void U(int k, int val){
  hotels[k/ROOTN][k % ROOTN] -= val;
  maxi[k/ROOTN] = 0;
  for(int i = 0; i<ROOTN; i++) maxi[k/ROOTN] = max(maxi[k/ROOTN], hotels[k/ROOTN][i]);
}

void precomp(){
  for(int i = 0; i<n; i++){
    hotels[i/ROOTN][i % ROOTN] = arr[i];
    maxi[i/ROOTN] = max(maxi[i/ROOTN], arr[i]);
  }
}


void print(){
  for(int i = 0; i<n/ROOTN; i++) printf("%d ", maxi[i]); puts("");
  for(int i = 0; i<=n/ROOTN; i++){
    for(int j = 0; j<ROOTN; j++){
      printf("%d ", hotels[i][j]);
    }
  }
  puts("");
}


int main(){ //first time using sqrt decomp
	scanf("%d%d", &n, &q);
  for(int i = 0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  precomp();
  for(;q--;){
    int a, res;
    scanf("%d", &a);
    res = Q(a);
    printf("%d ", res);
    if(res) U(res - 1, a);
  }
	return 0;
}

