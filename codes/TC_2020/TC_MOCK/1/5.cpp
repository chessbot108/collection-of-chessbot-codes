//code by aaron
#include <iostream>
using namespace std;
long long n;
int main() {
  cin >> n;
  long long cur = 1ll;
  for(int i = 1; i < n; i++)
  {
    cur = (cur + 1ll) * 2ll;
  }
  cout << cur << endl;
  return 0;
}
