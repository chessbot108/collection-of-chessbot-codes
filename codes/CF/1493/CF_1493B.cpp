#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>

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
const int MX = 1e5 +10, int_max = 0x3f3f3f3f;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}


const int good[] = {0, 1, 2, 5, 8};

int dig(int d){
  for(int i = 0; i<5; i++) if(good[i] == d) return 1;
  return 0;
}

int valid(int h, int m){
  return dig(h%10) && dig(h/10) && dig(m%10) && dig(m/10);
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
  int T, m, h; cin >> T >> h >> m; 
  while(T--){
    string a;
    cin >> a;
    int h = (a[0] - '0') * 10 + (a[1] - '0')
    int m = (a[3] - '0') * 10 + (a[4] - '0');
    for(; ; m++){
      if(m == 60) m =0, h++;
      if(h == 24)
    }
  } 



	return 0;
}


