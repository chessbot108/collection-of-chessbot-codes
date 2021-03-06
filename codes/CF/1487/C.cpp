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

int arr[max_v];


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    memset(arr, 0, sizeof(arr));
    if(n%2 == 1){
      for(int i = 0; i<(n-1)/2; i++){
        arr[i] = 1;
        arr[(n-1)/2 +i] = -1;
      }
    }else{
      for(int i = 0; i<(n-1)/2; i++){
        arr[i] = 1;
      }
      arr[(n-1)/2] = 0;
      for(int i = (n-1)/2 +1; i<n-1; i++){
        arr[i] = -1;
      }
    }
    //for(int i = 0; i<n-1; i++) cout << arr[i] << ' '; cout << endl;
    for(int i = 0; i<n; i++){
      for(int j = 0; j<(n-1)-i; j++){
        cout << arr[j] << ' ';
      }
    }
    cout << '\n';
  }
	return 0;
}

