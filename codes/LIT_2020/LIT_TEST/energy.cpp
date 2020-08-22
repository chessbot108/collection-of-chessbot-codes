//code by william
#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <queue>

using namespace std;

#define MAXN 11000
#define MAXT 40
#define INF 999999999
#define ll long long
#define pint pair<ll,ll>

ll n, m, t;
ll costs[MAXN];
ll dp[MAXN][MAXT];
vector<pint> graph[MAXN];

int main() {
	scanf("%lld%lld%lld", &n, &m, &t);
	for (int i = 0; i < n; i++)
		scanf("%lld", &costs[i]);
	for (int i = 0; i < m; i++) {
		ll n1, n2, c; scanf(" %lld%lld%lld", &n1, &n2, &c);
		n1--, n2--;
		graph[n1].push_back(make_pair(n2, c));
		graph[n2].push_back(make_pair(n1, c));
	}


	for (int i = 0; i < n; i++)
		for (int c = 0; c <= t; c++)
			dp[i][c] = INF;
	dp[0][t] = 0;

	queue<int> q;
	q.push(0);

	while (q.size()) {
		int node = q.front(); q.pop();
		// cout << node << " " << q.size() << endl;
		for (pint pear : graph[node]) {
			bool chg = false;

			for (int i = 0; i <= t; i++) {
				for (int j = 0; j <= t; j++) {
					if (i + j - pear.second < 0 || i + j > t || (j != 0 && costs[node] == 0)) continue;

					if (dp[pear.first][i+j-pear.second] > dp[node][i] + costs[node] * j) {
						chg = true;
						dp[pear.first][i+j-pear.second] = dp[node][i] + costs[node] * j;
					}
				}
			}
			if (chg) q.push(pear.first);
		}
	}
	for (int i = 1; i < n; i++) {
		ll thisone = INF;
		for (int j = 0; j <= t; j++) thisone = min(thisone, dp[i][j]);
		printf("%lld ", thisone >= INF ? -1 : thisone);
	}
	printf("\n");
  return 0;
}
