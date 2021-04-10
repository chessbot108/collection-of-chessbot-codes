#include <iostream>
#include <algorithm>
#define ll long long
#define moo printf
#define mool puts("")
using namespace std;
const int max_v = 2e5 + 10;
int arr[max_v], srt[max_v], freq[max_v];
int n, k;
int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> k;
  for(int i = 0; i<n; i++){
    cin >> arr[i];
    srt[i] = arr[i];
  }
  sort(srt, srt + n);
  for(int i = 0; i<n; i++){
    arr[i] = 1 + lower_bound(srt, srt + n, arr[i]) - &srt[0];
  }
  //for(int i = 0; i<n; i++) moo("%d ", arr[i]);  mool;
  int r = 0, tot = 0;
  ll ans = 0ll;
  for(int i = 0; i<n; i++){
    for(; r < n; r++){
      if(freq[arr[r]] == 0){
        if(tot == k) break;
        tot++;
      }
      freq[arr[r]]++;
    }
    if(freq[arr[i]] == 1) tot--;
    freq[arr[i]]--;
    ans += (ll)(r - i);
  }
  moo("%lld\n", ans);
  return 0;
}
