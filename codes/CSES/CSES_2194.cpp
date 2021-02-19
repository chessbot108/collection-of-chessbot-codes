#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#define max_v 220000
#define cont continue
#define x first
#define y second
#define ll long long
#define pb(n) push_back((n))
#define mp(a, b) (make_pair((a), (b)))
const ll ll_max = (long long)(1e18) + 10ll; //1e9 ^ 2
using namespace std;
long long ans = ll_max;
vector<pair<ll, ll>> p;
int n, m;
ll srt[max_v], arr[max_v];





int main(){
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    ll a, b;
    scanf("%lld%lld", &a, &b);
    p.pb(mp(a, b));
    srt[i] = a;
  }
  sort(srt, srt + n);
  sort(p.begin(), p.end());
  
  for(int i = 0; i<n; i++){
    arr[i] = srt[i];
  }

  

  for(int i = 0; i<n; i++){
    for(int j = i + 1; j < n; j++){
      ll X = p[i].x - p[j].x;
      if(X * X >= ans) cont;
      ll Y = p[i].y - p[j].y;
      ans = min(ans, X * X + Y * Y);
    }
  }
  
  printf("%lld\n", ans);

  return 0;
}


