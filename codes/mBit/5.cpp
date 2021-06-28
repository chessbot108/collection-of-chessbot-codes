/*
ID: varunra2
LANG: C++
TASK: knockout
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "lib/debug.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define debug_arr(...) \
  cerr << "[" << #__VA_ARGS__ << "]:", debug_arr(__VA_ARGS__)
#pragma GCC diagnostic ignored "-Wsign-compare"
//#pragma GCC diagnostic ignored "-Wunused-parameter"
//#pragma GCC diagnostic ignored "-Wunused-variable"
#else
#define debug(...) 42
#endif

#define int long long

#define EPS 1e-9
#define IN(A, B, C) assert(B <= A && A <= C)
#define INF (int)1e9
#define MEM(a, b) memset(a, (b), sizeof(a))
#define MP make_pair
#define PB push_back
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define x first
#define y second

const double PI = acos(-1.0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef map<int, int> MPII;
typedef multiset<int> MSETI;
typedef set<int> SETI;
typedef set<string> SETS;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<string> VS;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto& a : x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;
#pragma GCC diagnostic ignored "-Wsign-compare"
// util functions

const int MOD = (int)1e9 + 7;

int fact[(1 << 18)];
int invfact[(1 << 18)];

int binpw(int x, int pw) {
  if (pw == 0) return 1;
  if (pw == 1) return x;
  int ret = 1;
  ret = binpw(x, pw / 2);
  ret *= ret;
  ret %= MOD;
  if (pw % 2) {
    ret *= x;
    ret %= MOD;
  }
  return ret;
}

int inv(int x) { return binpw(x, MOD - 2); }

int perm(int n, int k) {
  if (n < k) return 0;
  int num = fact[n];
  int den = 1;
  den *= invfact[n - k];
  den %= MOD;
  return (num * den) % MOD;
}

int comb(int n, int k, VI& fact) {
  if (n < k) return 0;
  int num = fact[n];
  int den = fact[k];
  den *= inv(fact[n - k]);
  den %= MOD;
  return (num * den) % MOD;
}

void ad(int& a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  if (a < 0) a += b;
}

int32_t main() {
  // #ifndef ONLINE_JUDGE
  // freopen("knockout.in", "r", stdin);
  // freopen("knockout.out", "w", stdout);
  // #endif
  cin.sync_with_stdio(0);
  cin.tie(0);

  int pw;
	cin >> pw;
	//pw = 17;
  int n = (1 << pw);

  fact[0] = 1;

  for (int i = 1; i <= n; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= MOD;
  }

  invfact[0] = 1;
  for (int i = 1; i <= n; i++) {
    invfact[i] = inv(fact[i]);
  }

  VI vals(n);

  for (int i = 0; i < n; i++) {
		cin >> vals[i];
		//vals[i] = 1e9 - (i * 14);
  }

  sort(all(vals), greater<ll>());

  //debug(vals);

  int ret = vals[0] * pw;
  ret %= MOD;
  ret *= fact[n - 1];
  ret %= MOD;

  for (int i = 1; i < n; i++) {
    int exp = 0;
    int smlr = i, bigr = n - 1 - i;
    for (int j = 0; j < pw; j++) {
      int cnt = (1 << j);
      int rst = n - cnt;
      // number of ways to make it so that you pass j rounds...
      int psj = perm(bigr, cnt - 1);
      // number of ways to make sure that you fail on the j + 1th round
      // choose at least one smaller
      // total - choose none
      int p1 = perm(rst, cnt);
      int p2 = perm(bigr - cnt + 1, cnt);
      int fsj = p1 - p2;
      // how to put the rest
      int rstt = fact[rst - cnt];
      int tot = psj * fsj;
      tot %= MOD;
      tot *= rstt;
      tot %= MOD;
      // ^^ total number of ways to win j rounds
      ll curexp = tot;
      curexp *= ((((ll)(j - 1) * (ll)vals[i]))%MOD);
			//curexp += MOD;
			curexp %= MOD; 
			curexp += MOD;
			exp += curexp;
      // debug(curexp, tot, psj, fsj, rstt, cnt, rst, p1, p2, i, j);
    }
    ret += exp;
    ret %= MOD;
  }

  ret *= inv(fact[n - 1]);
  ret %= MOD;

  cout << ret << '\n';

  return 0;
}
