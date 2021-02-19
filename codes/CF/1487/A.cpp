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

int freq[max_v], arr[max_v];
int n, t;
int main(){
	cin.tie(0) -> sync_with_stdio(0);
  cin >> t;
  while(t--){
    cin >> n;
    memset(arr, 0, sizeof(arr));
    memset(freq, 0, sizeof(freq));
    for(int i = 0; i<n; i++){
      cin >> arr[i];
      freq[arr[i]]++;
    }

    for(int i = 0; i<=100; i++){
      if(freq[i]){
        n -= freq[i];
        break;
      }
    }
    cout << n << '\n';

  }
	return 0;
}

