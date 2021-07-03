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
const int MX = 2e5 +10, MXAI = 1e7+10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int freq[MXAI], arr[MX], low[MXAI], n, k;
int dp[MX][40], le[MX][40];
vector<int> primes;

void seive(){
  for(int i = 2; i<=1e7; i++){
    if(!low[i]){
      primes.pb(i);
      low[i] = i;
    }
    for(int j = 0; j < siz(primes) && primes[j] <= low[i] && i*primes[j] <= 1e7; j++){
      low[i*primes[j]] = primes[j];
    }
  }
}

int norm(int a){
  //normalizing a, or ridding a of all perfect sqaures
  for(int i = a; i != 1; i/=low[i]){
    while(a%(low[i]*low[i]) == 0) a /= (low[i]*low[i]);
  }
  return a;
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  seive();
  int T; cin >> T;
  while(T--){
    cin >> n >> k;
    bckt(arr, 0, n);
    for(int i = 0; i<n; i++){
      cin >> arr[i];
      arr[i] = norm(arr[i]);
    }
		
		for(int j = 0; j<=k; j++){
			int l = n, op = 0;
			for(int i = n-1; ~i; i--){
				while(l - 1 >= 0 && ((freq[arr[l-1]] && op < j) || (!freq[arr[l-1]] && op <= j))){
					l--;
					if(freq[arr[l]]) op++;
					freq[arr[l]]++;
				}	
				le[i][j] = l;
				if(freq[arr[i]] != 1) op--;
				orz(freq[arr[i]]);
				freq[arr[i]]--;
			}
		}
		
		for(int i = 1; i<=n; i++){
			for(int j = 0; j<=k; j++){
				dp[i][j] = int_max;
				for(int l = 0; l<=j; l++){
					dp[i][j] = min(dp[i][j], dp[le[i - 1][l]][j - l] + 1);
				}
			}
		}

		for(int i = 0; i<n; i++) freq[arr[i]] = 0; //sanity check
		int ans = int_max;
		for(int i = 0; i<=k; i++) ans = min(ans, dp[n][i]);
		moo("%d\n", ans);
  }
	return 0;
}


