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
#include <set>

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

set<ll> arr, ins;


int main(){
	cin.tie(0) -> sync_with_stdio(0);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t;
  cin >> t;
  while(t--){
    arr.clear(); ins.clear();
    int n, k;
    cin >> n >> k;
    //cout << "\ttc" << t << endl;
    //n = 1e5, k = 1e9;
    for(int i =0 ; i<n; i++){
      ll a; cin >> a;
      //ll a = i;
      arr.insert(a);
    } 
    ll mex = 0ll;
    for(ll x : arr){
      if(mex == x) mex++;
      else break;
    }
    if(mex >= arr.size()){
      cout << k + arr.size() << '\n';
      cont;
    }   
    while(k--){
      ll a = (*(--(arr.end())));
      ll temp = (a + mex + 1ll)/2ll;
      //cout << "\t" << temp << " " << mex << " "<< a << endl;
      if(ins.count(temp)) break;
      ins.insert(temp);
      arr.insert(temp);
      for(auto it = arr.lower_bound(mex); it != arr.end(); it++){
        if(*it == mex) mex++;
        else break;
      }
    }
    cout << arr.size() << "\n";

  } 
	return 0;
}


