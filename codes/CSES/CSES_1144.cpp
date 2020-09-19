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

#define max_v 210000
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

#define op first
#define a second.first
#define b second.second

using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int arr[max_v], srt[max_v * 3], BIT[max_v * 3];
pair<int, pair<int, int> > q[max_v];
int n, Q, ind = 1;

void U(int k, int val){ for(; k <= ind; k += lsb(k)) BIT[k] += val; }
int S(int k){ return (!k) ? 0 : BIT[k] + S(k - lsb(k)); }
int get_ind(int key){ return lower_bound(srt + 1, srt + ind, key) - &srt[0]; } 


void print(){
  for(int i = 1; i<ind; i++){
    printf("%3d", srt[i]);
  }
  puts("");
  for(int i = 1; i<ind; i++){
    printf("%3d", S(i) - S(i - 1));
  } 
  puts("");
}


int main(){
	scanf("%d%d",  &n, &Q);
  for(int i = 0; i<n; i++){
    scanf("%d", &arr[i]);
    srt[ind++] = arr[i];
  }

  for(int i = 0; i<Q; i++){
    char str[max_v];
    scanf("%s%d%d", str, &q[i].a, &q[i].b);
    q[i].op = (str[0] == '?') ? 0 : 1;
    srt[ind++] = --q[i].a;
    srt[ind++] = q[i].b;
  }

  sort(srt + 1, srt + ind);
  for(int i = 0; i<n; i++) U(get_ind(arr[i]), 1);
	for(int i = 0; i<Q; i++){
    //print();
    if(q[i].op){
      U(get_ind(arr[q[i].a]), -1);
      arr[q[i].a] = q[i].b;
      U(get_ind(arr[q[i].a]), 1);
    }else{
      int A = S(get_ind(q[i].a)), B = S(get_ind(q[i].b));
      //printf("from 0 to %d -> %d\nfrom 0 to %d -> %d\n", q[i].a, A, q[i].b, B);
      printf("%d\n", B - A);
    }
  }

  return 0;
}

