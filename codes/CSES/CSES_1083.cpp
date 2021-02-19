#include <iostream>
using namespace std;
long long n, ans;
int main(){
  cin >> n;
  for(int i = 0; i<n - 1; i++){
    long long a;
    cin >> a;
    ans += a;
  }
  cout << ((n * (n + 1ll))/2ll) - ans << "\n";

  return 0;
}
