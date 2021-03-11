#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>

#define cont continue
#define pow2(n) (1 << (n))
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))

const ll mod = 1e9 + 7;
const int MX = 1e5 +10, int_max = 0x3f3f3f3f;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}


int main(){
	cin.tie(0) -> sync_with_stdio(0);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  ll u, v;
  cin >> u >> v;
  if(u%2 != v%2 || u > v){
    //two edge cases. the xor of two numbers is always <= the sum due to how the 1'bits are made
    //if the two have a differnt parity, its bound to die :duck:
    cout << "-1\n";
  }else if(u == v){
    if(!u) cout << "0\n";
    else cout << "1\n" << u << "\n";
  }else{
    ll x = (v-u)/2ll;
    //for any 2 numbers that made it this far [u, x, x] will always work. 
    //since the sum of the elements is u + 2*((v-u)/2) == u + (v-u) == v 
    //and the xor is u ^ x ^ x and x^x = 0 so its just u
    //but if the case that u^x does not mess up any bits you can just merge the two
    //thats the case here where u&x == 0
    if((u^x) != (u+x)){
      cout << "3\n" << u << " " << x << " " << x << "\n";
    }else{
      cout << "2\n" << (ll)(u^x) << " " << x << "\n";
    }
  }
  //editorial op
	return 0;
}


