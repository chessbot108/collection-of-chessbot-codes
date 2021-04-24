//william 0/150

#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

#define ll long long
#define INF 10e15

struct Edge
{
	int n1;
	ll cost;

	Edge(int a, ll c) {
		n1=a,cost=c;
	}
};

bool operator<(Edge a, Edge b) {return (a.cost == b.cost) ? (a.n1 < b.n1) : (a.cost < b.cost);}

int n, m;
vector<Edge> graph[300];

vector<int> lastn[300], nextn[300], ng[300];
ll cdist[300];
bool ans[300];

void dijkstra(int source) {
	set<Edge> curr;
	for (int i = 0; i < n; i++)
		cdist[i] = INF, lastn[i].clear();
	cdist[source] = 0;
	for (int i = 0; i < n; i++)
		curr.insert(Edge(i, cdist[i]));

	while (curr.size()) {
		Edge e = *curr.begin(); curr.erase(curr.begin());
		int thisn = e.n1; ll thisd = e.cost;

		for (Edge thate : graph[thisn]) {
			int i = thate.n1, c = thate.cost;
			if (cdist[i] > c + thisd) {
				lastn[i].clear();
				lastn[i].push_back(thisn);

				curr.erase(Edge(i, cdist[i]));
				cdist[i] = c + thisd;
				curr.insert(Edge(i, cdist[i]));
			}

			else if (cdist[i] == c + thisd)
				lastn[i].push_back(thisn);
		}
	}
	lastn[source].push_back(-1);
}

bool reached[300];

void solve(int source) {
	for (int i = 0; i < n; i++) nextn[i].clear();

	for (int i = 0; i < n; i++)
		for (int j : lastn[i]) {
			if (j == -1) continue;
			//cout << i << " " << j << " " << source << endl;
			nextn[j].push_back(i);
		}

	for (int i = 0; i < n; i++) {
		if (ans[i]) continue;
		if (i == source) continue;

		for (int j = 0; j < n; j++) reached[i] = false;
		queue<int> q;

		q.push(source);
		reached[source] = true;

		while (q.size()) {
			int k = q.front(); q.pop();
			for (int j : nextn[k]) {
				if (j != i && !reached[j])
					reached[j] = true, q.push(j);
			}
		}

		for (int j = 0; j < n; j++) {
			if (!reached[j] && j != i) {
				//cout << i << " " << j << " " << source << endl;
				ans[i] = true;
				break;
			}
		}

	}

}

void bfs(int source) {
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++)
			reached[j] = false;

		queue<int> q; q.push(source);
		reached[source] = true;

		while (q.size()) {
			int t = q.front(); q.pop();
			for (int j : ng[t]) {
				if (j != i && !reached[j]) {
					reached[j] = true;
					q.push(j);
				}
			}
		}

		for (int j = 0; j < n; j++) {
			if (!reached[j] && j != i) {
				ans[i] = true;
			}
		}
	}
}

int main() {
	scanf(" %d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int n1, n2; ll c;
		scanf(" %d%d%lld", &n1, &n2, &c);
		n1--; n2--;
		graph[n1].push_back(Edge(n2, c));
		graph[n2].push_back(Edge(n1, c));

		ng[n1].push_back(n2);
		ng[n2].push_back(n1);
	}

	for (int i = 0; i < n; i++) ans[i] = false;

	for (int i = 0; i < n; i++) bfs(i);

	
	for (int i = 0; i < n; i++) {
		dijkstra(i);
		//for (int j = 0; j < n; j++)
			//cout << cdist[j] << " " << j << " " << i << " " << lastn[j][0] << endl;
		solve(i);

	}



	for (int i = 0; i < n; i++)
		if (ans[i])
			printf("%d ", i+1);
	printf("\n");


}
