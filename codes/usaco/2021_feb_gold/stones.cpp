#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;


int main(){
	cin.tie(0) -> sync_with_stdio(0);
  int n;
  cin >> n;
  if(n == 1) cout << 4;
  else if(n == 6) cout << 8;
  else if(n == 2){
    int a, b;
    cin >> a >> b;
    if(a > b) swap(a, b);
    int c= max((b + 1)/2, a);
    cout << b - c;
  }else cout << n - 1;
  cout << endl;
	return 0;
}
/**
 * try bashing
 * ll overflow
 * mod negatives
 * debug!!! assert!!!
 * dont forget to take all input
 * time matters!!!
 * dont start coding until you know how to solve it
 * have fun kek
**/

