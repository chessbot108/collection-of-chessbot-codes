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
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int arr[MX], n, col[MX];


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t; cin >> t;
  while(t--){
    cin >> n;
    for(int i = 1; i<=n; i++){
      cin >> arr[i];
      col[i] = 0;
    }
    int st = n;
    for(int i = n; i>0; i--){
      //if(col[i]) cont;
      
      for(int j = min(st, i); j>max(i - arr[i], 0); j--){
        col[j] = 1;
        st = j;
      }
    }

    for(int i = 1; i<=n; i++){
      cout << col[i] << " ";
    }
    cout << "\n";
    

  }
  

	return 0;
}


