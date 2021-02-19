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
#define ll long long
#define pow_2(n) (1 << (n))
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define LOG2(n) ((int)(ceil(log2((n)))))
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}
ll pre[max_v * 4], suf[max_v * 4], arr[max_v];
int n, q, s = 1;

void U(int p, ll val, int k, int L, int R){
  if(p < L || R <= p || R <= L) return ;
  if(L + 1 == R){
    assert(L == p);
    arr[p] = val;
    pre[k] = val - (ll)p;
    suf[k] = val + (ll)p;
    return ;
  }
  int mid = (L + R) / 2;
  U(p, val, LC(k), L, mid);
  U(p, val, RC(k), mid, R);
  pre[k] = min(pre[LC(k)], pre[RC(k)]);
  suf[k] = min(suf[LC(k)], suf[RC(k)]);
}

ll S(int qL, int qR, int k, int op, int L, int R){
  if(qR <= L || R <= qL || R <= L) return (ll)1e15;
  if(qL <= L && R <= qR) return (op) ? suf[k] : pre[k];
  int mid = (L + R) / 2;
  return min(S(qL, qR, LC(k), op, L, mid), S(qL, qR, RC(k), op, mid, R));
}



int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> q;
  while(s <= n) s *= 2;
  for(int i = 0; i<n; i++){
    cin >> arr[i];
  }
  memset(pre, 0x3f, sizeof(pre));
  memset(suf, 0x3f, sizeof(suf));
  for(int i = 0; i<n; i++){
    U(i, arr[i], 0, 0, s);
  }
  while(q--){
    int op; cin >> op;
    if(op == 1){
      int a, b; cin >> a >> b;
      U(a - 1, (ll)b, 0, 0, s);
    }else{
      int a; cin >> a;
      ll L = S(0, a - 1, 0, 0, 0, s), R = S(a, s, 0, 1, 0, s);
      cout << min({L + (a - 1ll), R - (a - 1ll), arr[a - 1]}) << '\n';
    }
  }
  


	return 0;
}

