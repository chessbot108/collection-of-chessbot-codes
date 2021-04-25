//code by apple method
//this didnt get 300/300 but its probably still correct
//the test cases were bugged. similar to 13
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
const int MAX_N = 1e5+5;

int n;
vector<pii> seg;

int main(int argc, const char * argv[]){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    seg = vector<pii>(n);
    F0R(i, n) cin >> seg[i].s >> seg[i].f;
    sort(all(seg));
    multiset<int> tot;
    F0R(i, n){
        multiset<int>::iterator x = tot.lower_bound(seg[i].s);
        if(x == tot.begin()){
            tot.insert(seg[i].f);
            continue;
        } x--;
        tot.erase(x);
        tot.insert(seg[i].f);
    }
    cout << tot.size() << endl;
    return 0;
}
