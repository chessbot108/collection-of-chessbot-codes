#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>

#define max_v 210000
#define int_max 0x3f3f3f3f
#define cont continue
#define pow_2(n) (1 << (n))
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) ((a%mod + b%mod)%mod)
#define mul(a, b) ((a%mod * b%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))

const ll mod = 1e9 + 7;

using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int arr[max_v], n, k, lo = int_max, occ[max_v], vis[max_v];


int main(){
	cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> k;

  for(int i = 1; i<=n; i++){
    cin >> arr[i];
  }
  for(int i = n; i > 0; i--){
    if(!occ[arr[i]]){
      occ[arr[i]] = i;
      vis[i] = 1;
      lo = arr[i];
    }else{
      if(arr[i] <= lo){
        vis[occ[arr[i]]] = 0;
        occ[arr[i]] = i;
        vis[i] = 1;
        lo = arr[i];
      }
    }
  } 
  for(int i = 1; i<=n; i++){
    if(vis[i]){
      cout << arr[i] << ' ';
    }
  }
  cout << '\n';
	return 0;
}


