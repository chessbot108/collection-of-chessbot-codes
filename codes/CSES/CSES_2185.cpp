#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>

#define int_max 0x3f3f3f3f
#define cont continue
#define pow_2(n) (1 << (n))
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
const int max_v = 1e5 +10;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

ll primes[max_v];
ll n, k;


int main(){
	cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> k;
  for(int i = 0; i<k; i++){
    cin >> primes[i];
  }
  sort(primes, primes + k);
  ll tot = 0ll, res = 1ll;
  for(int i = 0; i<k; i++){
    if(n/res < primes[i]){
      break;
    }
    res *= primes[i];
    tot += n/res;
  }
  cout << tot << '\n';
	return 0;
}


