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
const int MAX_N = 1e5+5;
const int MAX_D = 20;
const ll MOD = 1000000007;
const ll INF = 1e18;

int n, m;
vector<pii> adj[MAX_N];
int dist[MAX_N];
map<string, int> mp;

void dfs(int curr, int par){
    for(pii child : adj[curr]){
        if(child.f == par) continue;
        dist[child.f] = dist[curr]+child.s;
        dfs(child.f, curr);
    }
}

int main(int argc, const char * argv[]){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    int cnt = 1;
    F0R(i, n-1){
        string a, b; int c;
        cin >> a >> b >> c;
        if(!mp[a]) mp[a] = cnt++;
        if(!mp[b]) mp[b] = cnt++;
        adj[mp[a]].push_back({mp[b], c});
        adj[mp[b]].push_back({mp[a], -c});
    }
    dfs(1, 0);
    F0R(i, m){
        string a, b; cin >> a >> b;
        cout << dist[mp[b]]-dist[mp[a]] << '\n';
    }
    return 0;
}
