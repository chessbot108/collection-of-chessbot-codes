//code by tomas
#include <bits/stdc++.h>
using namespace std;

bool check(int x, int arr[], int n, int m){
  int last = arr[0];
  --m;
  for(int i = 1; i < n; i++){
    if(arr[i] - last >= x){
      --m;
      last = arr[i];
    }
  }
  return m <= 0;
}

int main() {
  int n, m;
  cin >> n >> m;
  int arr[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int l = 0, r = 2000000000;
  while(l < r){
    int mid = (l + r + 1)/2;
    if(check(mid, arr, n, m)){
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << endl;
}
