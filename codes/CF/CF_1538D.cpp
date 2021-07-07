//gyrating cat enthusiast
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <utility>
#include <cassert>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <queue>
#include <set>

#define ll long long
#define lb long double
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ins insert
#define cont continue
#define siz(vec) ((int)(vec.size()))

#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define bckt(arr, val, sz) memset(arr, val, sizeof(arr[0]) * (sz+5))
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define tern(a, b, c) ((a) ? (b) : (c))
#define feq(a, b) (fabs(a - b) < eps)
#define abs(x) tern((x) > 0, x, -(x))

#define moo printf
#define oom scanf
#define mool puts("") 
#define orz assert
#define fll fflush(stdout)

const lb eps = 1e-9;
const ll mod = 1e9 + 7, ll_max = (ll)1e18;
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> pr;
int vis[MX];

int F(int x){
	int sum = 0;
	for(int e : pr){
		//if(e > x) break;
		while(x%e == 0){
			//cout << x << " " << e << endl;
			sum++;
			x /= e;
		}
	}
	return sum + (x > 1);
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
	for(int i = 2; i<=1e5; i++){
		if(!vis[i]) pr.pb(i);
		for(int j = i; j<=1e5; j += i) vis[j] = 1;
	}
	int T; cin >> T;
	while(T--){
		int a, b, k; cin >> a >> b >> k;
		int m = tern(a == b, 0, tern((a%b == 0) || (b%a == 0), 1, 2));
		int n = F(a) + F(b);
		//cout << m << " " << k << " " << n << endl;

		(((m <= k && k <= n) && (k != 1 || (k == 1 && m == 1))) && cout << "YES\n") || cout << "NO\n";
	}
  return 0;
}


