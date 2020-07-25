#include <bits/stdc++.h>
using namespace std;

//code by thomas;

int main(){
  int s, t, n;
  cin >> s >> t >> n;
  pair<int, int> arr[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i].first >> arr[i].second;
  }
  sort(arr, arr + n);
  int time[25];
  memset(time, 0, sizeof(time));
  for(int i = 0; i < n; i++){
    for(int j = arr[i].first; j < arr[i].second; j++){
      time[j]++;
    }
  }
  double ans = 0.0;
  for(int i = s; i < t; i++){
    ans += 1 - pow(0.98, time[i]);
  }
  cout << setprecision(0) << min(ans*100.0, 100.0) << endl;
}
