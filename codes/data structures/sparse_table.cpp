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

#define max_v 11000
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << (n))

using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

class sparse_table{
  int prefix[max_v], d_min[max_v][30], d_max[max_v][30];
  int n;
  
  public:
    sparse_table(int* arr, int n){
      this->n = n;
      memset(d_min, 0x3f, sizeof(d_min));
      for(int i = 0; i<n; i++){
        d_min[i][0] = arr[i];
        d_max[i][0] = arr[i];
        prefix[i + 1] = prefix[i] + arr[i];
      }

      for(int j = 1; j<=(int)ceil(log2(n)); j++){
        for(int i = 0; i<n; i++){
          d_min[i][j] = min(d_min[i][j - 1], d_min[i + pow_2(j - 1)][j - 1]);
          d_max[i][j] = max(d_max[i][j - 1], d_max[i + pow_2(j - 1)][j - 1]);
        }
      }

    }
    
    int query_min(int l, int r){
      int k = log2(r - l);
      return min(d_min[l][k], d_min[r - pow_2(k)][k]);
    }

    int query_max(int l, int r){
      int k = log2(r - l);
      return max(d_max[l][k], d_max[r - pow_2(k)][k]);
    }
    
    int query_sum(int l, int r){
      return prefix[r] - prefix[l];
    }

};

int arr[max_v];

int main(){
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++)
    scanf("%d", &arr[i]);

  sparse_table S(arr, n);

  int cmd;
  while(scanf("%d", &cmd)){
    if(cmd == -1) break;
    int a, b;
    scanf("%d%d", &a, &b);
    a--, b--;
    if(cmd == 1){
      printf("%d\n", S.query_min(a, b));
    }else if(cmd == 2){
      printf("%d\n", S.query_max(a, b));
    }else if(cmd == 3){
      printf("%d\n", S.query_sum(a, b));

    }

  }
	return 0;
}

