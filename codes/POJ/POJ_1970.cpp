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

#define max_v 50
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

int x[] = {1, 1, 0, -1}; // tilted. only count the directions that i, j is the LEFTMOST of. very tilted
int y[] = {0, 1, 1, 1};
int arr[max_v][max_v], n = 19;

int check(int i, int j, int k){//recursive checking is the cleanest
  if(arr[i][j] == arr[i + x[k]][j + y[k]]){
    return 1 + check(i + x[k], j + y[k], k);
  }else{
    return 0;
  }
}

int main(){
  int T;
  for(scanf("%d", &T); T; T--){
    memset(arr, 0, sizeof(arr));
    for(int i = 1; i<=n; i++)
      for(int j = 1; j<=n; j++)
        scanf("%d", &arr[i][j]);

    int ans = 0, X, Y;
    for(int i = 1; i <= n; i++){ //one based indexing makes code cleaner and avoids certain fencposts
      for(int j = 1; j <= n; j++){
        if(ans || !arr[i][j]) cont; //invalid cases
        for(int k = 0; k<4; k++){
          int cnt = check(i, j, k);
          if(cnt == 4 && arr[i][j] != arr[i - x[k]][j - y[k]]){
            ans = arr[i][j], X = i, Y = j;
            i = n + 1; j = n + 1; break;
          }
        }
      }
    }
    if(!ans) printf("0\n");
    else printf("%d\n%d %d\n", ans, X, Y);
  }



  return 0;
}
