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
vector<pii> ans;
int arr[MX];
int main(){
  cin.tie(0) -> sync_with_stdio(0);
	int n; cin >> n;
	queue<int> q, a, b;
	cout << "? 1" << endl;
	for(int i = 1; i<=n; i++){
		int x; cin >> x;
		if(x%2 == 0){ if(i != 1) a.push(i); }
		else b.push(i);
		if(x == 1){
			ans.pb(mp(1, i));
		}
	}
	
	if(siz(a) < siz(b)) q = a;
	else q = b;

	while(!q.empty()){
		int x = q.front(); q.pop();
		cout << "? " << x << endl;
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
			if(arr[i] == 1){
				ans.pb(mp(min(i, x), max(i, x)));
			}
		}
	}
	cout << "!" << endl;
	sort(ans.begin(), ans.end());
	int m = unique(ans.begin(), ans.end()) - ans.begin();
	ans.resize(m);
	orz(siz(ans) == n-1);
	for(const pii& e : ans){
		cout << e.first << " " << e.second << endl;
	}
	fll;
  return 0;
}

