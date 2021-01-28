#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#define max_v 1100000
#define int_max 0x3f3f3f3f
#define cont continue

#define lsb(n) ((n)&(-(n)))
using namespace std;

void setIO(const string& file_name){
  freopen((file_name+".in").c_str(), "r", stdin);
  freopen((file_name+".out").c_str(), "w+", stdout);
}

struct query{
  int x, y, amt, ind, v;
} arr[max_v], tmp[max_v];
int BIT[max_v], ans[max_v/4], psum[1100][1100], st[1100][1100], rec[max_v], n, Q, h, sz;
char str[max_v];

int S(int k){ return (!k) ? 0 : BIT[k] + S(k - lsb(k)); }
void U(int k, int val){ for(; k && k <= n; k += lsb(k)) BIT[k] += val; } 

void dnq(int l, int r){ //[l, r)
  if(l + 1 >= r) return ;
  int mid = (l + r)/2;
  dnq(l, mid); dnq(mid, r);
  int j = l, k = mid, sum = 0, cnt = 0;
  while(j < mid || k < r){
    if(k == r || (j < mid && arr[j].x <= arr[k].x)){
      U(arr[j].y, arr[j].v);
      rec[sum++] = arr[j].y * arr[j].v;
      tmp[cnt++] = arr[j++];
    }else{
      ans[arr[k].ind] += S(arr[k].y) * arr[k].amt;
      tmp[cnt++] = arr[k++];
    }
  }
  assert(cnt == r - l);
  for(int i = 0; i<sum; i++){ 
    if(rec[i] < 0) U(-rec[i], 1); else U(rec[i], -1);
  }

  for(int i = l; i<r; i++)
    arr[i] = tmp[i - l];
  
}

int main(){
  //cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> Q;
  for(int i = 1; i<=n; i++){
    scanf("%s", str);
    for(int j = 1; j<=n; j++) st[i][j] = psum[i][j] = (str[j - 1] == '.') ? 0 : 1;
  }

  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n; j++){
      psum[i][j] += psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
    }
  }

  for(int i = 0; i<Q; i++){
    int op; cin >> op;
    if(op - 1){
      int a, b, c, d;
      cin >> a >> b >> c >> d; a--, b--;
      arr[sz++] = {a, b, 1, h, 0};
      arr[sz++] = {a, d, -1, h, 0};
      arr[sz++] = {c, b, -1, h, 0};
      arr[sz++] = {c, d, 1, h, 0};
      ans[h++] += (psum[a][b] + psum[c][d]) - (psum[a][d] + psum[c][b]);
    }else{
      int a, b;
      cin >> a >> b;
      arr[sz++] = {a, b, 0, 0, (st[a][b]^1) ? 1 : -1};
      st[a][b] ^= 1;
    }
  }
  dnq(0, sz);
  for(int i = 0; i<h; i++){ 
    cout << ans[i] << '\n';
  }

  return 0;
}

