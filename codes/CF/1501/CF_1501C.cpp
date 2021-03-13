//test 6, just gonna use 20
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>

#define cont continue
#define pow2(n) (1 << (n))
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))
//geniousity limit exceeded
#define moo printf
#define oom scanf
const ll mod = 1e9 + 7;
const int MX = 5e6 +10, int_max = 0x3f3f3f3f;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

pii arr[MX];
int arr1[MX], arr2[MX];
int ind1[MX], ind2[MX];
int n, ans = 0;

void bashing(){
  for(int i = 0; i<n; i++){
    for(int j = i + 1; j<n; j++){
      for(int k = j + 1; k<n; k++){
        for(int h = k + 1; h<n; h++){
          if(arr[i].first + arr[j].first == arr[k].first + arr[h].first){
            moo("YES\n%d %d %d %d\n", ++i, ++j, ++k, ++h);
            return ;
          }else if(arr[i].first + arr[k].first == arr[j].first + arr[h].first){
            moo("YES\n%d %d %d %d\n", ++i, ++k, ++j, ++h);
            return ;
          }else if(arr[i].first + arr[h].first == arr[j].first + arr[k].first){
            moo("YES\n%d %d %d %d\n", ++i, ++h, ++j, ++k);
            return ;
          }
        }
      }
    }
  }
  moo("NO\n");
}


void solve(){
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  for(int T =0; T<20; T++){
    init(ind1, 0);
    init(ind2, 0);
    init(arr1, 0);
    init(arr2, 0);
    for(int i = 1; i<n; i++){
      swap(arr[i], arr[rng()%i]);
    }
    for(int i = 0; i<1e6; i++){
      int a = rng()%(n/2), b = rng()%(n/2), sum = arr[a].first + arr[b].first;
      //moo("a and b %d %d, %d\n", arr[a].second, arr[b].second, sum);
      if(a == b) cont;
      arr1[sum] = arr[a].second;
      arr2[sum] = arr[b].second;
    }
    for(int i = 0; i<1e6; i++){
      int a = rng()%(n/2) +(n/2), b = rng()%(n/2) +(n/2), sum = arr[a].first + arr[b].first;
      //moo("a and b %d %d, %d\n", arr[a].second, arr[b].second, sum);
      if(a == b) cont;
      if(arr1[sum]){
        moo("YES\n%d %d %d %d\n", arr1[sum] + 1, arr2[sum] + 1, arr[a].second + 1, arr[b].second + 1);
        return ;
      }
    }
  }
  moo("NO\n");
}



int main(){
  oom("%d", &n);
  for(int i = 0; i<n; i++){
    oom("%d", &arr[i].first); arr[i].second = i;
  }
  if(n <= 150) bashing();
  else solve();
  return 0;
}

