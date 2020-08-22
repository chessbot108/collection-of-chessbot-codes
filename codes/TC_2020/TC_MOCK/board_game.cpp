#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int arr[n];
  bool vis[n + 1];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  int ind = 1;
  int steps = 0;
  bool fail = false;
  while(true){
    vis[ind] = true;
    if(arr[ind - 1] == 0) break;
    if(!vis[arr[ind - 1]]){
      ind = arr[ind - 1];
      steps++;
    } else {
      fail = true;
      break;
    }
  }
  if(fail) cout << -1 << endl;
  else cout << steps << endl;
}
