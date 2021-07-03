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
#define bckt(arr, val, sz) memset(arr, val, sizeof(arr[0]) * ((sz)+5))
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

int sum[MX*4], tag[MX*4], lz[MX*4];
char str[MX], tar[MX];
int n, q, s = 1;
vector<pii> ve;

int eval(int k, int L, int R){
	return tern(lz[k], tag[k] * (R - L), sum[k]);
}

void push(int k, int L, int R){
	if(L + 1 == R) return ;
	if(lz[k]){
		tag[LC(k)] = tag[RC(k)] = tag[k];
		lz[LC(k)] = lz[RC(k)] = 1;
		sum[LC(k)] = sum[RC(k)] = 0;
	}
	int mid = (L + R)/2;
	lz[k] = 0;
	sum[k] = eval(LC(k), L, mid) + eval(RC(k), mid, R);
}

void U(int qL, int qR, int k, int v, int L, int R){
	if(qR <= L || R <= qL || R <= L) return ;
	if(qL <= L && R <= qR){
		tag[k] = v;
		lz[k] = 1;
		sum[k] = 0;
		return ;
	}
	push(k, L, R);
	int mid = (L + R)/2;
	U(qL, qR, LC(k), v, L, mid);
	U(qL, qR, RC(k), v, mid, R);
	sum[k] = eval(LC(k), L, mid) + eval(RC(k), mid, R);
}

int S(int qL, int qR, int k, int L, int R){
	if(qR <= L || R <= qL || R <= L) return 0;
	if(qL <= L && R <= qR) return tern(lz[k], tag[k] * (R - L), sum[k]);
	push(k, L, R);
	int mid = (L + R)/2;
	return S(qL, qR, LC(k), L, mid) + S(qL, qR, RC(k), mid, R);
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		cin >> n >> q;
		for(s = 1; s<n; s*=2){}
		bckt(sum, 0, s*2);
		bckt(lz, 0, s*2);
		bckt(tag, 0, s*2);
		bckt(str, 0, n);
		bckt(tar, 0, n);
		ve.clear();
		cin >> str >> tar;
		for(int i = s - 1; i<s+n-1; i++){
			sum[i] = tar[i -(s-1)] - '0';
		}
		for(int i = s - 2; ~i; i--){
			sum[i] = sum[LC(i)] + sum[RC(i)];
		}
		while(q--){
			int a, b; cin >> a >> b;
			ve.pb(mp(a - 1, b));
		}
		int ans = 1;
		for(int i = siz(ve)-1; ~i; i--){
			int l = ve[i].first, r = ve[i].second;
			int tot = S(l, r, 0, 0, s), sz = r - l;
			if(tot + tot == sz){
				ans = 0; break;
			}
			if(tot > sz - tot){
				U(l, r, 0, 1, 0, s);
			}else{
				U(l, r, 0, 0, 0, s);
			}
		}
		for(int i = 0; i<n; i++) tar[i] = S(i, i+1, 0, 0, s) + '0';
		for(int i = 0; i<n; i++) if(tar[i] != str[i]) ans = 0;
		(ans && cout << "YES\n") || cout << "NO\n";
	}
  return 0;
}


