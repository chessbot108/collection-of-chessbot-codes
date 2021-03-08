//right off a cnblogs
//my approach was also prolly correct
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
const int MX = 1e5 +10, int_max = 0x3f3f3f3f;
const int SQRT = 320;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int arr[MX], b[MX], jumps[MX], par[MX], lpos[MX];
int n, q;

int up(int i){
  return i*SQRT;
}

int down(int i){
  return (i*SQRT) - SQRT +1;
}

void recompute(int l, int r){
  r = min(r, n);
  for(int i = r; i >= l; i--){
    int nex = i + arr[i];
    if(nex > n || nex > up(b[i])){
      jumps[i] = 1;
      par[i] = nex;
      lpos[i] = i;
    }else{
      jumps[i] = jumps[nex] +1;
      par[i] = par[nex];
      lpos[i] = lpos[nex];
    }
  }
}


int main(){
	cin.tie(0) -> sync_with_stdio(0);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin >> n >> q;
  for(int i = 1; i<=n; i++){
    cin >> arr[i];
    b[i] = (i - 1)/SQRT +1;
  }
  recompute(1, n);
  while(q--){
    int op; cin >> op;
    if(op == 0){
      int a, B;
      cin >> a >> B;
      arr[a] = B;
      recompute(down(b[a]), up(b[a]));
    }else{
      int a; cin >> a;
      int p = a, l = a, j = 0;
      while(p <= n){
        j += jumps[p];
        l = lpos[p];
        p = par[p];
      }
      cout << l << " " << j << '\n';
    }

  }
	return 0;
}


