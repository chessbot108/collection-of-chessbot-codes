//code by apple method
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define f first
#define s second
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define F0R(i, x) FOR(i, 0, x)
#define FORd(i, a, b) for(int i = (b)-1; i >= (a); i--)
#define F0Rd(i, x) FORd(i, 0, x)
#define ckif(a, b, c) ((c) ? (a) : (b))
const int MAX_N = 51;
const ll MOD = 1000000007;
const ll INF = 1e18;

ll n, k, l;
ll grid[MAX_N][MAX_N], dp[MAX_N][MAX_N][11];

int main(int argc, const char * argv[]){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k >> l;
    F0R(i, n) F0R(j, n){
        char x; cin >> x;
        if(x == 'S') grid[i][j] = 1;
    }
    F0R(i, n) F0R(j, n){
        ll num = 0;
        FOR(i1, i, n) FOR(j1, j, n)
            num += grid[i1][j1];
        if(num >= l) dp[i][j][0] = 1;
    }
    FOR(k1, 1, k+1) F0R(i, n) F0R(j, n){
        ll num = 0;
        FOR(i1, i, n){
            FOR(j1, j, n)
                num += grid[i1][j1];
            if(num >= l) dp[i][j][k1] = (dp[i][j][k1]+dp[i1+1][j][k1-1])%MOD;
        }
        num = 0;
        FOR(j1, j, n){
            FOR(i1, i, n)
                num += grid[i1][j1];
            if(num >= l) dp[i][j][k1] = (dp[i][j][k1]+dp[i][j1+1][k1-1])%MOD;
        }
    }
    cout << dp[0][0][k] << endl;
    return 0;
}
