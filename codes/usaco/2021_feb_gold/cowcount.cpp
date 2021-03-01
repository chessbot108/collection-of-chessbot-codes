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
#define ll long long
using namespace std;



int main(){
	cin.tie(0) -> sync_with_stdio(0);
  int n;
  cin >> n;
  while(n--){
    ll a, b, d, ans = 0;
    cin >> d >> a >> b;
    if(a == 1000000000000000000ll){ cout << a + 1 << '\n'; continue; }
    for(ll i = 0; i<=d; i++){
      bool works = 1;
      for(ll j = 1; j<=1e18; j *= 3ll){
        if(((a/j)%3ll)%2ll != ((b/j)%3ll)%2ll) works = false;
      }
      a++, b++;
      if(works) ans++;
    }

    cout << ans << '\n';
  }
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

