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
#define cont continue

#define pow2(n) (1 << (n))
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ins insert
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define tern(a, b, c) ((a) ? (b) : (c))
//the following ones give off usaco vibes
#define pbenq priority_queue
#define moo printf
#define oom scanf
#define mool puts("") 
#define loom getline

const ll mod = 1e9 + 7;
const int MX = 2e5 +10, NLOGN = 1e7, int_max = 0x3f3f3f3f, s = pow2(30);

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int sum[NLOGN], lc[NLOGN], rc[NLOGN];
int arr[MX], n, k, ind;


void U(int p, int val, int& k, int L, int R){
  if(p < L || R <= p || R <= L) return ;
  if(!k) k = ++ind;
  if(L + 1 == R){
    assert(L == p);
    sum[k] += val;
    return ;
  }
  int mid = (L + R)/2;
  U(p, val, lc[k], L, mid);
  U(p, val, rc[k], mid, R);
  sum[k] = sum[lc[k]] + sum[rc[k]];
}

int S(int kth, int k, int L, int R){
  if(L + 1 == R) return L; //praydge
  int mid = (L + R)/2, dist = sum[lc[k]];
  if(dist > kth) return S(kth, lc[k], L, mid);
  else return S(kth - dist, rc[k], mid, R);
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> k;
  for(int i = 0; i<n; i++){
    cin >> arr[i];
  } 
  int x = k/2 + k%2, root = 0; //praydge
  //moo("%d\n", x);
  for(int i = 0; i<n; i++){
    U(arr[i], 1, root, 0, s);
    //moo("point %d: \n\tupdated %d with +1\n", i + 1, arr[i]);
    if(i - k >= 0){
      //moo("\tupdated arr[%d] -> %d with -1\n", i + 1 - k, arr[i]);
      U(arr[i - k], -1, root, 0, s);
    }
    if(i + 1 >= k) moo("%d ", S(x - 1, root, 0, s)); 
    
  }
  mool;
	return 0;
}


