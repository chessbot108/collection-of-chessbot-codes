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
#include <list>

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

const char al[] = {'A', 'N', 'O', 'T'};

char str[MX];
char ans[4], temp[4];

ll cnt[300], inv[300][300];

int main(){
  cin.tie(0) -> sync_with_stdio(0);
	int T; oom("%d", &T);
	while(T--){
		scanf("%s", str);
		int n = strlen(str);
		//init(cnt, 0);
		for(int i = 0; i<n; i++){
			cnt[str[i]]++;
		}	
		//for(int i = 0; i<4; i++){
			//cout << cnt[al[i]] << " ";
		//} cout << endl;
		for(int i = 0; i<4; i++){
			int cur = 0;
			for(int j = 0; j<n; j++){
				inv[al[i]][str[j]] += cur;
				if(str[j] == al[i]) cur++;
			}
		} //4-way inversion table
		for(int i = 0; i<4; i++) ans[i] = al[i];
		ll best = 0;
		do{
			ll tot = 0;
			for(int i = 0; i<4; i++){
				for(int j = i+1; j<4; j++){
					tot += inv[ans[j]][ans[i]];
				}
			}
			if(tot >= best){
				best = tot;
				for(int i = 0; i<4; i++) temp[i] = ans[i]; //rip i messed up the naming
			}
		}while(next_permutation(ans, ans + 4));
		for(int i = 0; i<4; i++){
			while(cnt[temp[i]]-- > 0) moo("%c", temp[i]);
		} mool;
		for(int i = 0; i<4; i++) for(int j = 0; j<4; j++) inv[al[i]][al[j]] = cnt[al[i]] = 0;
	}
  return 0;
}


