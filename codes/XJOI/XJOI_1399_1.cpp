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

#define max_v 55000
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << (n))

using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int d[max_v  *2][20], t[max_v * 2][20];

class sparse_table{
  
  public:
    sparse_table(int n, int* arr){
      memset(t, byte_max, sizeof(t));
      for(int i = 0; i<n; i++){
        t[i][0] = arr[i];
        d[i][0] = arr[i];
      }
      
      for(int j = 1; j<=16; j++){
        for(int i = 0; i<n; i++){
           d[i][j] = max(d[i][j - 1], d[i + pow_2(j - 1)][j - 1]);
           t[i][j] = min(t[i][j - 1], t[i + pow_2(j - 1)][j - 1]);
        }
      }

    }

    int query_max(int l, int r){
      int k = log2(r - l);
      return max(d[l][k], d[r - pow_2(k)][k]);
    }

    int query_min(int l, int r){
      int k = log2(r - l);
      return min(t[l][k], t[r - pow_2(k)][k]);
    }

};

int arr[max_v];


int main(){
	int n, q;
  scanf("%d%d", &n, &q);
  
  for(int i = 0; i<n; i++){
    scanf("%d", &arr[i]);
  }

  sparse_table s(n, arr);
  
  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    int p = s.query_min(l, r);
    int q = s.query_max(l, r);
    printf("%d\n", q - p);
  }
  
	return 0;
}

