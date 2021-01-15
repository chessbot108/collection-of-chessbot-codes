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
using namespace std;
const int SQRT = 500;
 
struct query{
  int l, r, ind;
  query(){}
  
  bool operator < (const query& b) const{
    return (l/SQRT != b.l/SQRT) ? l < b.l : r < b.r;
  }
 
};
 
int arr[max_v], srt[max_v], occ[max_v], ans[max_v];
query q[max_v];
int n, m;
 
 
 
void solve(){
  int L = 0, R = -1, res = 0;
  for(int i = 0; i<m; i++){
    int l = q[i].l - 1, r = q[i].r - 1;
    
    while(L < l)
      if(!(--occ[arr[L++]])) res--;
    
    while(L > l)
      if(!(occ[arr[--L]]++)) res++;
 
 
    while(R > r)
      if(!(--occ[arr[R--]])) res--;
    
    while(R < r)
      if(!(occ[arr[++R]]++)) res++;
 
    //assert(res >= 0);
    ans[q[i].ind] = res;
 
  }
 
}
 
 
 
 
int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for(int i = 0; i<n; i++){
    cin >> arr[i];
    srt[i] = arr[i];
  }
 
  for(int i = 0; i<m; i++){
    cin >> q[i].l >> q[i].r; q[i].ind = i;
  }
 
  sort(srt, srt + n);
  sort(q, q + m);
  
  for(int i = 0; i<n; i++){
    arr[i] = 1 + (lower_bound(srt, srt + n, arr[i]) - &srt[0]);
  }
  solve();
  for(int i = 0; i<m; i++){
    cout << ans[i] << '\n';
  }
 
  
 
	return 0;
}
