#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;
long long arr[220000], pre[220000], n, x, ans;
map<long long, int> mp;
int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> x;
  mp[0] = 1;
  for(int i = 1; i<=n; i++){
    cin >> arr[i];
    pre[i] = pre[i - 1] + arr[i];
    ans += mp[pre[i] - x];
    mp[pre[i]]++;
  } 
  cout << ans << '\n';
  return 0;
}
