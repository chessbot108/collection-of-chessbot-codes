#include <iostream>
using namespace std;
void F(long long n){
  cout << n;
  if(n == 1) return ;
  cout << " ";
  if(n&1) F(n*3ll + 1ll);
  else F(n/2ll);
}

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  F(n);
  return 0;
}
