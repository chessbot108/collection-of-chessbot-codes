#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <list>
#include <queue>
#include <stack>
//#include <unordered_map>
//#include <unordered_set>
#include <functional>

#define max_v 1100
#define int_max 0x3f3f3f3f
#define cont continue
#define pow_2(n) (1 << (n))
#define ll long long
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define LOG2(n) ((int)(ceil(log2((n)))))
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--){
    ll n, k; cin >> n >> k;
    if(n%2ll == 0ll){
      ll ans = (k)%n;
      cout << (ans ? ans : n) << endl;
      cont;
    }
    ll x = n/2ll;
    k--;
    k %= (n * x);
    //k is now 0 based
    ll skipped = k/x;
    ll should = k%n;
    ll ans = skipped + should + 1ll;
    ans %= n;
    if(ans) cout << ans;
    else cout << ans + n;
    cout << endl;
  }
	return 0;
}

