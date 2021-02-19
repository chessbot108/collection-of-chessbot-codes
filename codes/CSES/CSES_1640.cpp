#include <map>
#include <iostream>
#define ll long long
using namespace std;
map<ll, int> mp;
ll n, x;
int main(){
  cin >> n >> x;
  int a = -1, b = -1;
  for(int i = 0; i<n; i++){
    ll t; cin >> t;
    if(mp.count(x - t)){
      a = mp[x - t];
      b = i + 1;
      break;
    }
    mp[t] = i + 1;
  }
  if(a == -1) cout << "IMPOSSIBLE\n";
  else cout << a << " " << b << '\n';
  return 0;
}
