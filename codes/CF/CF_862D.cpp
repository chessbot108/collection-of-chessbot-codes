//here take a cat
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <utility>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <queue>
#include <set>

#define ll long long
#define lb long double
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ins insert
#define cont continue
#define pow2(n) (1 << (n))

#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define sof(arr) sizeof(arr) //alternative for flexible memset?
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define tern(a, b, c) ((a) ? (b) : (c))
#define feq(a, b) (fabs(a - b) < eps)

#define pbenq priority_queue
#define moo printf
#define oom scanf
#define mool puts("") 
#define loom getline
#define orz assert

const lb eps = 1e-9;
const ll mod = 1e9 + 7;
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, start;

char str[MX];

void Q(){
  cout << "? ";
  for(int i = 0; i<n; i++){
    cout << str[i];
  }
  cout << endl;
}

void rng_bash(int p0, int p1, int q){ //value v, with q queries
  while(q--){
    if(p0 && p1) break;
    int d = uid(0, n);
    str[d] = '0';
    Q();
    int a; cin >> a;
    if(a != start){
      if(a < start) p0 = a;
      else p1 = a;
    }
  }
  moo("%d %d\n", p0, p1);
}

bool check(int x){
  memset(str, '1', sof(str));
  for(int i = 0; i<=x; i++) str[i] = '0';
  Q();
  int x; cin >> x;
  return (x <= start);
}


int bin_search(int l, int r){
  int mid = (l + r)/2;
  if(l == r) return l;
  if(check(mid)){
    return bin_search(l, mid + 1);
  }else{
    return bin_search(mid + 1, r);
  }
}



int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  memset(str, '1', sof(str));
  Q();
  cin >> start;

  //if d is between 30% and 70% of n ill rng bash
  //or else ill binsearch and bash for the lesser one
  
  //if(n * .3 <= d && d <= n * .7){
    rng_bash(0, 0, 14);
  //}

  return 0;
}


