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
//tree
#define ll long long
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
    ll n; cin >> n;
    ll est = (ll)floor(sqrt(n*2ll));
    if(est%2ll == 0ll) est -= 1ll;
    cout << est/2ll << '\n';
    /**
     * taken from bashing.cpp
     int est = (int)floor(sqrt(n*2));
     est -= (1 - est%2);
     cout << cnt  << " " << est/2 << endl;

     **/
  }
  return 0;
}

