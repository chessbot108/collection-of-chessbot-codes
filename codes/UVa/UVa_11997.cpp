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
#include <queue>

#define max_v 800
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)

using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

struct dist{
  int key;
  int row;
  dist(int a, int b){
    key = a, row = b;
  }
  bool operator < (const dist& b) const{
    return key > b.key;
  }

};

int best[max_v], arr[max_v];
//priority_queue<dist> pq;

int main(){
	int n;
  while(scanf("%d", &n)){
     if(n == -1) break;
     for(int i = 0; i<n; i++)
        scanf("%d", &best[i]);
     sort(best, best + n);

     for(int i = 1; i<n; i++){
       for(int j = 0; j<n; j++)
          scanf("%d", &arr[j]);

       sort(arr, arr + n);

       priority_queue<dist> pq;

       for(int j = 0; j<n; j++){
         pq.push(dist(best[j] + arr[0], 0));
       }
       
       for(int j = 0; j<n; j++){
         dist cur = pq.top(); pq.pop();
         best[j] = cur.key;
         if(cur.row+1 < n)
          pq.push(dist(cur.key - arr[cur.row] + arr[cur.row + 1], cur.row + 1));
       }

     }
      
     for(int i = 0; i<n - 1; i++)
        printf("%d ", best[i]);
     printf("%d\n", best[n - 1]);
  }
	return 0;
}

