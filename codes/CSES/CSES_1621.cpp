#include <iostream>
#include <set>
using namespace std;
set<int> s;
int main(){
  int n; cin >> n;
  while(n--){
    int a; cin >> a;
    s.insert(a);
  }
  cout << s.size();
  return 0;
}
