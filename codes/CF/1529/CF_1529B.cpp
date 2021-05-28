//gyrating cat enthusiast
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <utility>
#include <cmath>
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
#define bckt(arr, val, sz) memset(arr, val, sizeof(arr[0]) * (sz))
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define tern(a, b, c) ((a) ? (b) : (c))
#define feq(a, b) (fabs(a - b) < eps)

#define moo printf
#define oom scanf
#define mool puts("") 
#define orz assert
#define fll fflush(stdout)
#define int ll //war crimes!!!!!

const lb eps = 1e-9;
const ll mod = 1e9 + 7, ll_max = (ll)1e18;
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int arr[MX], n;


signed main(){
  cin.tie(0) -> sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		cin >> n; bckt(arr, 0, n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		//wtmoooooooooooooooooooooo
		sort(arr, arr + n);
		//take all negatives
		//take one positive
		if(n == 1){
			moo("1\n"); cont; //ahhhhhhhhh
		}
		int z = 0, tot = 0, m = int_max, ind = -1;
		for(int i = 0; i<n; i++){
			if(arr[i] < 0){
				tot++;
				m = min(tern(i, arr[i] - arr[i-1], m), m);
			}
			if(arr[i] == 0) z++;
			if(arr[i] > 0 && arr[i] <= m){
				ind = arr[i]; break;
			}
		}
		//moo("%d\n", ind); //why am i bricking so hard
		if(z > 1){
			moo("%d\n", tot + z);
		}else{
			if(~ind){
				if(z){                                //dont ask
					if(ind <= 0 - tern(tot, arr[tot-1], -int_max)) moo("%d\n", tot + z + 1);
					else moo("%d\n", tot + z);
				}else{
					moo("%d\n", tot + 1);
				}
				
			}else{
				moo("%d\n", tot + z); //i have given up on life
			}
		}	

		
	}
  return 0;
}


