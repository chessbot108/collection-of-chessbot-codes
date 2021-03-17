#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
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
#define init(arr, val, sz) memset(arr, val, sizeof(arr[0]) * (sz))
//geniousity limit exceeded
#define moo printf
#define oom scanf
const ll mod = 1e9 + 7;
const int MX = 1e5 +10, int_max = 0x3f3f3f3f;
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int freq[MX], arr[MX], n, m, T;


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> T;
  while(T--){
    cin >> n >> m;
    init(freq, 0, m + 10);
    for(int i = 0; i<n; i++){
      cin >> arr[i];
      freq[arr[i]%m]++;
    }

    //i dislike case analysis
    int ans = 0;
    if(freq[0]) ans++; //you can put all the mod m == 0's into 1 array
    for(int i = 1; i<=m/2; i++){
      if(i == m - i){
        if(freq[i]) ans++; //in the even m is even, all of the mod m == m/2's can be put together
      }else{
        int A = max(freq[i], freq[m - i]), B = min(freq[i], freq[m - i]);
        if(A == 0) cont;
        else if (B == 0) ans += A;
        else if(B == A || B + 1 == A){
          ans++; //case where all the numbers fit perfectly
        }else{
          ans++;
          A -= (B + 1);
          ans += A;
        } 
      }
    }
    moo("%d\n", ans);

  }
	return 0;
}


