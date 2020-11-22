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
long long x[max_v], y[max_v];
int n;

long long r;
long long dist(int a, int b){
  return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}
bool works(int a, int b){
  long long A = (x[a] - x[b]) * (x[a] - x[b]);
  long long B = (y[a] - y[b]) * (y[a] - y[b]);
  return A + B <= r * r;
}

long long area(int i, int j, int k){
  int d1 = dist(i, j);
  int d2 = dist(j, k);
  int d3 = dist(i, k);
  int sp = (d1 + d2 + d3) / 2;
  return (sp * (sp - d1) * (sp - d2) * (sp - d3));
}


int main(){
  scanf("%d%lld", &n, &r);
  for(int i = 0; i<n; i++){
    scanf("%lld%lld", &x[i], &y[i]);
  }
  long long ans =  0;

  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      for(int k = 0; k<n; k++){
        if(i != k && j != k && j != i) cont;
        if(works(i, j) && works(i, k) && works(j, k)){
          ans = max(ans, area(i, j, k));
        }
        
      }
    }
  }
  printf("%lld\n", (double)sqrt(ans) * 1000);
	return 0;
}

