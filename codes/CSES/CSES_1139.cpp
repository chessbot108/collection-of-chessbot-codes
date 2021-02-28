#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define max_v 220000
#define cont continue
#define pb push_back
using namespace std;

const int SQRT = 500;

struct query{
  int l, r, ind;
  query(){}

  bool operator <(const query& b) const{
    return (l/SQRT != b.l/SQRT) ? l < b.l : r < b.r;
  }

} q[max_v];

int arr[max_v], srt[max_v], occ[max_v], l[max_v], r[max_v], ord[max_v * 2], ans[max_v], trav[max_v];
int n, ind = -1;
vector<int> adj[max_v];

void dfs(int u, int p){
  ord[++ind] = u;
  l[u] = ind;
  for(int v : adj[u])
    if(v != p)
      dfs(v, u);

  r[u] = ind;
}

void solve(){
  int L = 0, R = -1, res = 0;

  for(int i = 0; i<n; i++){
    int l = q[i].l, r = q[i].r;
    
    while(L < l)
      if(!(--occ[trav[L++]])) res--;
    
    while(L > l)
      if(!(occ[trav[--L]]++)) res++;
 
 
    while(R > r)
      if(!(--occ[trav[R--]])) res--;
    
    while(R < r)
      if(!(occ[trav[++R]]++)) res++;
    
    ans[q[i].ind] = res;
  }

}


int main(){
  cin >> n;
  
  for(int i = 0; i<n; i++){
    cin >> arr[i];
    srt[i] = arr[i];
  }

  for(int i = 1; i<n; i++){
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  
  dfs(0, -1);
  sort(srt, srt + n);
  for(int i = 0; i<n; i++){
    q[i].l = l[i];
    q[i].r = r[i];
    q[i].ind = i;
    arr[i] = lower_bound(srt, srt + n, arr[i]) - &srt[0];
    trav[i] = arr[ord[i]];
  }

  sort(q, q + n);
  solve();
  for(int i = 0; i<n; i++){
    cout << ans[i] << ' ';
  }


  return 0;
}
