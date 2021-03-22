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

#define moo printf
#define oom scanf
#define mool puts(""); 
#define loom getline
//const ll mod = 1e9 + 7;
const int MX = 1e5 +10, int_max = 0x3f3f3f3f;
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}
int arr[MX];


void solve(){
  int n; cin >> n;
  int mod = -1, c;
  for(int i = 0; i<n; i++){
    cin >> arr[i];
  }
  if(n <= 2){
    moo("0\n");
    return ;
  }
  int del = arr[1] - arr[0];
  for(int i = 2; i<n; i++){
    int t = arr[i] - arr[i-1];
    if(t == 0 || del == 0){
      if(t != del){
        moo("-1\n"); return ;
      }
    }else if((t>0 && del>0) || (t<0&&del<0)){
      if(t != del || (mod != -1 && arr[i] >= mod)){
        moo("-1\n"); return ;
      }
    }else if(t<0 && del >0){
      int tmod = del - t;
      if(mod == -1){ mod = tmod, c = del; cont;}

      if(tmod != mod){
        moo("-1\n"); return ;
      }else{
        c = del;
      }
    }else if(t>0&&del<0){
      int tmod = t - del;
      if(mod == -1){ mod =tmod, c = t; cont;}
      if(tmod != mod){
        moo("-1\n"); return ;
      }else{
        c = t;
      }
    }
  }
  if(mod == -1){
    moo("0\n"); return ;
  }
  if(arr[0] >= mod){
    moo("-1\n"); return ;
  }
  for(int i = 1; i<n; i++){
    if((arr[i -1] + c)%mod != arr[i] || arr[i] >= mod){
      moo("-1\n"); return ;
    }
  }
  
  
  moo("%d %d\n", mod, c);
  
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--){
    solve();
  }

	return 0;
}


