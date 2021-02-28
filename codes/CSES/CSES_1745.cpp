#include <iostream>
#include <algorithm>
using namespace std;
int dp[110000], arr[110], n, x, cnt;
int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i<n; i++){ cin >> arr[i]; x += arr[i]; }
  sort(arr, arr + n);
  dp[0] = 1;
  for(int i = 0; i<n; i++){
    for(int j = x+1; j >= arr[i]; j--){
      dp[j] |= dp[j - arr[i]];
    }
  }
  for(int i = 1; i<=x; i++) cnt += dp[i];
  cout << cnt << '\n';
  for(int i = 1; i<=x; i++){
    if(dp[i]) cout << i << " ";
  }
  return 0;
}
