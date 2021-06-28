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

char str[MX], pat[10];
int n;

bool check(int len){
	//imagine knowing kmp
	for(int i = 0; i<n; i++){
		for(int j = 0; j<len; j++){
			if(str[i + j] != pat[j]) break;
			if(j == len - 1){
				//moo("%d %d %c %s %s\n", i, j, str[i + j], str, pat);
				return 0;
			}
		}
	}
	return 1;
}

void solve(){
	init(pat, 0);

	for(char c = 'a'; c <= 'z'; c++){
		pat[0] = c;
		if(check(1)){
			moo("%s\n", pat); return ;
		}
	}

	for(char b = 'a'; b <= 'z'; b++){	
		for(char c = 'a'; c <= 'z'; c++){
			pat[0] = b; pat[1] = c;
			if(check(2)){
				moo("%s\n", pat); return ;
			}
		}
	}

	for(char a = 'a'; a <= 'z'; a++){
		for(char b = 'a'; b <= 'z'; b++){	
			for(char c = 'a'; c <= 'z'; c++){
				pat[0] = a, pat[1] = b, pat[2] = c;
				if(check(3)){
					moo("%s\n", pat); return ;
				}			
			}
		}
	}
} //pray



int main(){
  cin.tie(0) -> sync_with_stdio(0);
	int T; oom("%d", &T);
	while(T--){
		oom("%d", &n);
		bckt(str, 0, n);
		oom("%s", str);
		//moo("%s\n", str);
		solve();	
	}
  return 0;
}


