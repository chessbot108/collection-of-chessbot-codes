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

const ll mod = 1e9 + 7;
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int n, q;
int arr[MX], cap[MX], par[MX];

int find(int x){ if(x != par[x]) par[x] = find(par[x]); return par[x]; }
void Union(int a, int b){
  a = find(a), b = find(b);
  if(a == b) return ;
  par[min(a, b)] = max(a, b);
}

void mkdsu(){
  for(int i = 0; i<=n + 1; i++) par[i] = i;
}

void U(int k, int val){
  for(; k<=n && val;){
    if(arr[k] + val >= cap[k]){
      val -= (cap[k] - arr[k]);
      arr[k] = cap[k];
      Union(k, k + 1);
      k = find(k);
    }else{
      arr[k] += val;
      break;
    }
  }
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin >> n;
  for(int i = 1; i<=n; i++){
    cin >> cap[i];
  }
  cin >> q;
  mkdsu();
  while(q--){
    int op; cin >> op;
    if(op == 1){
      int a, b; cin >> a >> b;
      U(a, b);
    }else{
      int a; cin >> a;
      cout << arr[a] << '\n';
    }
  }
	return 0;
}


