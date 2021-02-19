#include <iostream>
#include <algorithm>
using namespace std;
const int max_v = 2e5 + 10;
int arr[max_v], srt[max_v], freq[max_v];
int n, x;
int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> x;
  for(int i = 0; i<n; i++){
    cin >> arr[i];
    arr[i] = srt[i];
  }
  sort(srt, srt + n);
  for(int i = 0; i<n; i++){
    arr[i] = lower_bound(srt, srt + n, arr[i]) - &srt[0];
  }

  int tot = 0, l = 0;


  return 0;
}
