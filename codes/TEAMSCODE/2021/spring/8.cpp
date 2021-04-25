//code by izhang
//text cases bugged so it didnt get 300/300
//still convinced the code is correct tho

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

#define int long long

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
bool visited[maxn];
int n;

long long t[2 * maxn];

long long calc(long long a, long long b) {
    return a + b;
}

void update(int p, long long val) {
    for (t[p += n] = val; p > 1; p /= 2) {
        t[p / 2] = calc(t[p], t[p ^ 1]);// p ^ 1 is the other child for node p / 2
    }
}

long long query(int l, int r) {// [l,r)
    long long res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) {
            res = calc(res, t[l++]);
        }
        if (r & 1) {
            res = calc(res, t[--r]);
        }
    }
    return res;
}
signed main() {
    setIO("1");

    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<long long> pre(n), goes(n);
    for (int i = 0; i < n; ++i) {
        goes[i] = -1;
    }
    for (int i = 0; i < n - 1; ++i) {
        int b, c;
        cin >> b >> c;
        --b, --c;
        ++pre[b];
        goes[c] = b;
    }
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        if (pre[i] == 0) {
            q.push({a[i], i});
        }
    }
    long long sol = 0;
    while (!q.empty()) {
        pair<int, int> cur = q.top();
        q.pop();
        sol += 3 * cur.first;
        visited[cur.second] = true;
        sol += query(0, cur.second);
#ifdef DEBUG
        cout << 3 * cur.first << " " << query(0, cur.second) << "\n";
#endif
        update(cur.second, cur.first);
        long long ne = goes[cur.second];
        if (ne != -1) {
            if (!visited[ne] && --pre[ne] == 0) {
                q.push({a[ne], ne});
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
