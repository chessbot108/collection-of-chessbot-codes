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

#define max_v 110000000
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
/**
 *if i had coded this before TC i couldn't gotten 14 on the test. i think
 *>:(
 *welp here we go
 **/

bool prime[max_v];
int arr[5700000];
int num = 0;
/**
  the whole point of linear sieve is to be linear 
  this is possible since for the regular sieve (how do you spell it?)
  you overcount numbers. this method does not overcount
  so basically if a number is prime, you start at the first number that 

 **/
void seive(int n){
  for(int i = 2; i<=n; i++) prime[i] = true;
  for(int i = 2; i*i <= n; i++){
    if(!prime[i]) cont;
    for(int j = *i; j <= n; j += i){
      prime[j] = false;
    }
  } 
}


int main(){
  int n;
  scanf("%d", &n);
  seive(n);
  return 0;
}

