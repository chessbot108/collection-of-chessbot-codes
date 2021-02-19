//polynomial queries
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <utility>
#define mp make_pair
#define ll long long
#define pii pair<int, int>
#define LC(k) ((k << 1) + 1)
#define RC(k) ((k + 1) << 1)
using namespace std;
const int RT = 450, max_v = RT * RT;
pii Q[RT];
ll arr[max_v], start[max_v], pre[max_v], N[max_v];
int n, q, ind = 0;
ll adj[max_v][RT]; //.first is the endpoint, .second is the duration

ll S(int L, int R, int qL, int qR){
  //the contribution an update from [L, R) has on
  //a query [qL, qR)
  if(L > qR || qL > R) return 0ll;
  ll l = (ll)max(qL, L), r = (ll)min(qR, R), sz = r - l;
  //sum of l + 1, l + 2, .., l + (sz - 1) + 1, l + sz
  return (qL - l) * sz + ((sz * (sz + 1ll))/2ll);
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> q;
  for(int i = 0; i<n; i++){
    cin >> arr[i];
    pre[i + 1] = pre[i] + arr[i];
  }
  while(q--){
    int op, a, b;
    cin >> op >> a >> b; a--;
    if(op == 1){
      Q[ind++] = mp(a, b);
      start[a]++;
      adj[b][N[b]++] = b - a;
      if(ind == 5){
        ll cnt = 0ll, contr = 0ll;
        for(int i = 0; i<=n; i++){
          while(N[i]--){
            cnt--; contr -= adj[i][N[i]]; 
            adj[i][N[i]] = 0ll;
          }
          cnt += start[i];
          contr += cnt;
          arr[i] += contr;
          pre[i + 1] = arr[i] + pre[i];
          start[i] = 0ll;
        }
        ind = 0;
      }
    }else{
      ll ans = pre[b] - pre[a];
      for(int i = 0; i<ind; i++){
        ans += S(Q[i].first, Q[i].second, a, b);
      }
      cout << ans << endl;
    }
  }

  return 0;
}
