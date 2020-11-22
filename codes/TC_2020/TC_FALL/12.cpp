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

#define max_v 2100000
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


int BIT[max_v], arr[max_v], srt[max_v];
int S(int k){ return (!k) ? 0 : BIT[k] + S(k - lsb(k)); }
void U(int k, int val){ for(; k<=max_v; k += lsb(k)) BIT[k] += val; }

int main(){
	int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    scanf("%d", &arr[i]);
    arr[i]++;
    srt[i] = arr[i];
  }
  sort(srt, srt + n);
  for(int i = 0; i<n; i++){
    arr[i] = lower_bound(srt, srt + n, arr[i]) - &srt[0] +1;
    printf("%d ", S(arr[i] - 1) + 1);
    U(arr[i], 1);
  }
   
  

	return 0;
}

