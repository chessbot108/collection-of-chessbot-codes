#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>

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
const int SQRT = 320, max_v = 1e5 +10;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}
//a 2700 nani?
//batch processing
//going to use a union find idea to guarantee O(n root n)
//wish me luck

struct query{
  int u, val, op;
  query(){}
  query(int a, int b){op = a, u = b;}
  query(int a, int b, int c){op = a, u = b, val = c;}
} todo[max_v];

int par[max_v], arr[max_v], jumps[max_v], vis[max_v];
int qu[max_v]; //you qu (chinese for interesting) also happened to be short for query :O
int n, q, ind = 0;


void recompute(){
  for(int i = n; i>=1; i--){
    if(i + arr[i] > n){
      jumps[i] = 1;
    }else if(qu[i]){
      jumps[i] = 1;
      par[i] = arr[i] + i;
    }else{
      if(qu[i + arr[i]]){
        
      }
    }
  }
  init(qu, 0);
}

void Q(int u){
  int tot = 0;
  while(u + arr[u] <= n){
    tot += jumps[u];
    u = par[u];
  }
  cout << u << ' ' << tot << '\n';
}


int main(){
	cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> q;
  for(int i = 1; i<=n; i++){
    cin >> arr[i];
  }
  for(int i = 0; i<q; i++){
    int op; cin >> op;
    if(op == 0){
      int a, b;
      cin >> a >> b;
      todo[ind++] = query(op, a, b);
      qu[a] = 1;
    }else{
      int a; 
      cin >> a;
      todo[ind++] = query(op, a);
    }
    if(ind == SQRT || i == q - 1){
      recompute();
      for(int j = 0; j<ind; j++){
        if(todo[j].op == 0){
          int a= todo[j].u, b = todo[j].val;
          arr[a] = b;
          par[a] = a + b;
        }else{
          Q(todo[j].u);
        }
      }
      ind = 0;
    }
  }
	return 0;
}


