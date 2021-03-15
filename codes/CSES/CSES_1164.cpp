#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
const int MX = 2e5 +10; //this part is not mandatory, but i really suggest using global arrays and constants for max size of input. it'll pay off later for harder problems
int ans[MX], n, MAX = 0;
stack<int> st;
vector<pair<int, int>> arr;

int main(){
  cin.tie(0) -> sync_with_stdio(0); //just add this in your int main for faster input/output
  cin >> n;
  for(int i = 0; i<n; i++){
    int a, b;
    cin >> a >> b;
    arr.push_back(make_pair(a, i + 1)); //note i+1 since there is an edge for for guest ID 0
    arr.push_back(make_pair(b + 1, -(i + 1)));
  }
  sort(arr.begin(), arr.end());
  for(int i = 0; i<n*2; i++){
    //cout << i << " " << arr[i].first << " " << arr[i].second << " " <<  MAX << "\n";
    //i think your edge case doesnt really matter here
    //since within the same day, numbers are sorted by 
    //ending before starting since ending is negative
    //if you get what i mean
    if(arr[i].second > 0){
      if(st.empty()){
        ans[arr[i].second] = MAX + 1; //MAX too small
        MAX++;
      }else{
        ans[arr[i].second] = st.top();//use the stack instead
        st.pop();
      }
    }else{
      st.push(ans[-arr[i].second]); //add it back
    }
  } 
  cout << MAX << "\n";
  for(int i = 1; i<=n; i++){
    cout << ans[i] << " " ;
  }
  cout << "\n"; //not needed but i think printing a newline is just good habit
  return 0;
}

