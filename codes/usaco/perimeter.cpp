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
const int MX = 1e3 +10, int_max = 0x3f3f3f3f;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

char arr[MX][MX];
bool vis[MX][MX];
int n, ar, A, P;
int dfs(int x, int y){
  if(x < 0 || y < 0 || x >= n || y >= n || arr[x][y] == '.') return 1;
  if(vis[x][y]) return 0;
  vis[x][y] = true;
  ar++;
  return dfs(x + 1, y) + dfs(x, y + 1) + dfs(x - 1, y) + dfs(x, y - 1);
}



int main(){
  cin.tie(0) -> sync_with_stdio(0);
  setIO("perimeter");
  oom("%d", &n);
  for(int i = 0; i<n; i++){
    scanf("%s", arr[i]);
  }
  A = 0, P = int_max;
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      if(!vis[i][j] && arr[i][j] == '#'){
        ar = 0;
        int res = dfs(i, j);
        if(A < ar || (A == ar && P > res)){
          P = res, A = ar;
        } 
      }
    }
  }
  moo("%d %d\n", A, P);
	return 0;
}


