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

#define max_v 110000
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

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}


int BIT[max_v], arr[max_v], n, K;
int S(int k){ return (!k) ? 0 : BIT[k] + S(k - lsb(k)); }
void U(int k, int val){ for(; k<=n; k+= lsb(k)) BIT[k] += val; }

int main(){
  //setIO("sleepy");
	scanf("%d", &n);
  for(int i = 1; i<=n; i++){
    scanf("%d", &arr[i]);
  }
  K = n;
  
  while(arr[K] > arr[K - 1]) K--;
  
  if(K == 0){
    printf("0\n");
    return 0; //heh heh 
  }

  printf("%d\n", K - 1);
  for(int i = K; i<=n; i++){
    U(arr[i], 1);
  }
    
  for(int i = 1; i<K - 1; i++){
    int steps = S(arr[i]) + (K - i - 1);
    printf("%d ", steps);
    U(arr[i], 1);
  }
  printf("%d\n", S(arr[K - 1])); //:_:
	return 0;
}

