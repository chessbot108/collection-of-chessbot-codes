//i give up, will upsolve later


//gyrating cat enthusiast
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
//does it help?

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
const int MX = 3e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int super[MX][40], n, q, dep[MX], cost[MX], cnt[MX], vis[MX];
int a0, c0;

int k_up(int u, int op){
	for(int i = 20; ~i; i--){
		while((super[u][i] != -1) && !vis[super[u][i]]){
			//moo("%d %d %d\n", u, i, super[u][i]);
			u = super[u][i];
		}
	}
	return u;
}

void setall(int u){
	for(int i = 1; (1 << i) <= q; i++) super[u][i] = -1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  cin.exceptions(cin.failbit);
	cin >> q >> a0 >> c0;
	//oom("%d%d%d", &q, &a0, &c0);
	cnt[0] = a0, cost[0] = c0;
	for(int i = 0; i<=q; i++) for(int j = 0; j<=30; j++) super[i][j] = -1;
	for(int i = 1; i<=q; i++){
		int op; //oom("%d", &op);
		cin >> op;
		if(op == 1){
			int p, a, b; //oom("%d%d%d", &p, &a, &b);
			cin >> p >> a >> b;
			super[i][0] = p, cnt[i] = a, cost[i] = b;
			dep[i] = dep[p]+1;
			for(int j = 1; (1 << j) <= q; j++){
				if(super[i][j-1] == -1) super[i][j] = -1;
				else super[i][j] = super[super[i][j-1]][j-1];
			}
		}else{
			int tot = 0; ll co = 0;
			int a, b, c; //oom("%d%d", &a, &b);
			cin >> a >> b;
			c = k_up(a, 0);
			while(tot <= b && cnt[a]){
				int t = b - tot;
				tot += min(cnt[c], t);
				co += (ll)(min(cnt[c], t)) * (ll)(cost[c]);
				cnt[c] -= min(cnt[c], t);
				if(cnt[c] == 0){
					//setall(c);
					vis[c] = 1;
				}
				if(c == a) break;
				c = k_up(a, 0);
			}
			cout << tot << " " << co << endl;
			//moo("%d %lld\n", tot, co); fll;
		}
	}
  return 0;
}
