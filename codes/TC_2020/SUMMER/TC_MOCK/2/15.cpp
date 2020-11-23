//code by weiming
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

#define max_v 22000
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

int BIT[max_v];

int S(int k){
  if(k <= 0) return 0;
  return BIT[k] ^ S(k - lsb(k));
}

void U(int k, int i){
  if(k >= max_v) return ;
  BIT[k] = (BIT[k]) ? BIT[k] ^ i : i;
  U(k + lsb(k), i);
}

int S(int a, int b){
  if(b < a) return 0;
  return S(b) ^ S(a - 1);
}


int main(){
	string com;
  while(!cin.eof()){
    cin >> com;
    if(com[0] == 'A'){
      int a;
      cin >> a;
      U(a, a);
    }else if(com[0] == 'R'){
      int a;
      cin >> a;
      U(a, a);
    }else {
      cin >> com;
      int a, b;
      cin >> a >> com >> b;
      cout << S(a, b) << endl;
    }

  
  }

	return 0;
}

