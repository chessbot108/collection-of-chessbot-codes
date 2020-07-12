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

char str[max_v], pat[max_v];
bool start[max_v]; //a match starts there
int pi[max_v];
void precomp(){
  int m = strlen(pat);
  memset(pi, 0, sizeof(pi));
  int k = 0;
  for(int i = 2; i<m; i++){
    printf("case %d\narr[i] == %c\nby default k = %d\nk changes from:", i, pat[i], k);
    while(k && pat[k + 1] != pat[i]){
      printf("\t%d -> %d\n", k, pi[k]);
      k = pi[k];
    }
    if(pat[k + 1] == pat[i]){
      k++;
    }
    printf("\tk ends at %d\n", k);
    pi[i] = k;
    puts("");
  }
}

void KMP(){
  int n = strlen(str);
  int m = strlen(pat);
  memset(start, 0, sizeof(start));
  precomp();
  int k = 0;
  for(int i = 2; i<n; i++){
    while(k && str[i] != pat[k + 1]){
      k = pi[k];
    }
    if(pat[k + 1] == str[i]){
      k++;
    }
    if(k == m){
      start[i - (m - 1)] = true;
      k = pi[k];
    }

  }
}

int main(){
	scanf("%s%s", str, pat);
  KMP();
  int m = strlen(pat);
  int n = strlen(str);
  for(int i = 0; i<m; i++){
    printf("%d\n", pi[i]);
  }
  for(int i = 0; i<n; i++){
    if(start[i]){
      printf("occ starts %d\n", i + 1);
    }
  }
	return 0;
}

