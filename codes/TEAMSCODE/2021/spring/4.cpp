//code by izhang

#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;


int main() {
    setIO("1");

    int n, m, r;
    cin >> n >> m >> r;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pair<int, int>> lit;
    for (int i = 0; i < n; ++i) {
        lit.emplace_back(max(a[i] - r, 0), a[i] + r);
    }
    sort(lit.begin(), lit.end());
    int sol = 0;
    if (lit[0].first != 0) {
        ++sol;
    }
    pair<int, int> last = lit[0];
    for (int i = 1; i < n; ++i) {
        if (lit[i].first - 1 <= last.second) {
            last.second = lit[i].second;
        } else {
            ++sol;
            last = lit[i];
        }
    }
    if (last.second < m - 1) {
        ++sol;
    }
    cout << sol << "\n";
    return 0;
}
