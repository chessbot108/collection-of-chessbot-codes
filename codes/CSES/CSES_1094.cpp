#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll arr[(int)2e5 +1], n, mx = 0ll, ans = 0ll;
int main(){
  cin >> n;
  for(int i = 0; i<n; i++){
    cin >> arr[i];
  }
  mx = arr[0];
  for(int i = 1; i<n; i++){
    if(arr[i] < mx){
      ans += mx - arr[i];
    }else{
      mx = arr[i];
    }
  }
  cout << ans << '\n';
  return 0;
}
