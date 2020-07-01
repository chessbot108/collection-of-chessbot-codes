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

#define max_v 1100
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)

using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int arr[1100000];

int main(){
	int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++)
    scanf("%d", &arr[i]);
  priority_queue<int> pq;
  for(int i = 0; i<n; i++)
    pq.push(arr[i]);

  for(int i = 0; i<n; i++){
    arr[n - (i + 1)] = pq.top();
    pq.pop();
  }
  for(int i = 0; i<n; i++)
    printf("%d ", arr[i]);
	return 0;
}

