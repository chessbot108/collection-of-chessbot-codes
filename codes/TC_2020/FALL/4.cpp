//me

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
#define int_max 0x3f3f3f3f
#define cont continue
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

int arr[max_v][max_v];






int main(){
	int n, T;
  scanf("%d", &T);
  while(T--){
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
      for(int j = 1; j<=n; j++){
        scanf("%d", &arr[i][j]);
      }
    }
    
    int tot = 0, tot2 = 0, tot3 = 0;

    for(int i = 1; i<=n; i++){
      tot += arr[i][i];
      tot2 += arr[n + 1 - i][i];
    }
    //printf("%d %d\n", tot, tot2); 
    if(tot != tot2){
      printf("0\n"); cont;
    }
    bool B = 1;
    for(int i = 1; i<=n && B; i++){
      tot2 = 0, tot3 = 0;
      for(int j = 1; j<=n; j++){
        tot2 += arr[i][j];
        tot3 += arr[j][i];
      }
      //printf("%d %d\n", tot2, tot3); 
      if(tot2 != tot3 || tot != tot2) B = false;
    }

    if(B) printf("1\n");
    else printf("0\n");



  }
  return 0;
}

