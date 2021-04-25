//code by apple method
//60/300 with a wa (should be tle :/) floyd warshal


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
const int MAX_N = 5001;
const ll MOD = 1000000007;
const ll INF = 1e18;

int n, m;
int floyd[MAX_N][MAX_N];

int main(int argc, const char * argv[]){
    cin >> n >> m;
    F0R(i, m){
        int a, b; cin >> a >> b; a--, b--;
        floyd[a][b] = 1;
    }
    F0R(k, n) F0R(i, n) F0R(j, n)
        floyd[i][j] = max(max(floyd[i][k], floyd[k][j]), floyd[i][j]);
    int ans = 0;
    F0R(i, n) FOR(j, i+1, n) if(floyd[i][j] || floyd[j][i])
        ans++;
    cout << ans << endl;
    return 0;
}
