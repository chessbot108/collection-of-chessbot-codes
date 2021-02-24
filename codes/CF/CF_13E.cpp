#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>

#define max_v 1100
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
const int SQRT = 320;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}
//a 2700 nani?
//batch processing
//going to use a union find idea to guarantee O(n root n)
//wish me luck

int par[max_v], arr[max_v], jumps[max_v];
int n, q;

void recompute(){
  for(int i = n; i; i--){
    if(arr[i] + i > n){
      par[i] = i;
      jumps[i] = 1;
    }else{
      par[i] = par[i + arr[i]];
      jumps[i] = jumps[i + arr[i]] + 1;
    }
  }
}

int dfs(int x, int& j){
  cout << x << ' ' << j << '\n';
  if(x + arr[x] > n) return x;
  j += jumps[x];
  return dfs(par[x], j);
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> q;
  for(int i = 1; i<=n; i++){
    cin >> arr[i];
  }
  recompute();
  int U = 0;
  for(int i = 0; i<q; i++){
    int op; cin >> op;
    if(op == 0){
      int a, b;
      cin >> a >> b;
      arr[i] = b;
      par[a] = (a + b > n) ? n : a + b;
      jumps[i] = 1;
      U++;
    }else{
      int a, j = 0; cin >> a;
      cout << "query for " << a << '\n';
      cout << dfs(a, j) << ' ' << j << '\n';
    }
    if(i % SQRT == 0) recompute();
  }
	return 0;
}


