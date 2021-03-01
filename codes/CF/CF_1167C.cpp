#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <utility>

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
const int int_max = 0x3f3f3f3f, max_v = 5e5 +10;
using namespace std;


int par[max_v], sz[max_v];

int find(int x){
  if(x != par[x]) par[x] = find(par[x]);
  return par[x];
}

void Union(int a, int b){
  a = find(a), b = find(b);
  if(a == b) return ;
  if(sz[a] > sz[b]) swap(a, b);
  par[a] = b;
  sz[b] += sz[a];
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i<=n; i++){
    par[i] = i;
    sz[i] = 1;
  }
  while(m--){
    int k, src; cin >> k;
    if(!k) cont;
    cin >> src;
    for(int i = 1; i<k; i++){
      int a; cin >> a;
      Union(a, src);
    }
  }
  for(int i = 1; i<=n; i++){
    cout << sz[find(i)] << " ";
  }
  cout << endl;
	return 0;
}

