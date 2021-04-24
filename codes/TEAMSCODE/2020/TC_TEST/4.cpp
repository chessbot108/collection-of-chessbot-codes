#include <iostream>
#include <string>
using namespace std;

int main(){
  int n; cin >> n;
  string s, prev_s, out = "";
  cin >> prev_s;
  out += prev_s;
  for(int i = 0; i < n - 1; i++){
    cin >> s;
    if(s != prev_s){
      out += " " + s;
    }
    prev_s = s;
  }

  cout << out << endl;
  return 0;
}

