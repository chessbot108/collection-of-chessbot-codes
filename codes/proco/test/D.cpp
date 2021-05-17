//code by bckt
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <cassert>
 
using namespace std;
 
#define MAXN 405
#define SQRT 69
#define INF 696969420
 
int n, m;
int grid[MAXN][MAXN];
int vert[MAXN][MAXN], horiz[MAXN][MAXN];
int dp[MAXN][MAXN][SQRT][4];
char s[MAXN];
 
struct state
{
	int r, c, speed, dir;
	state(int _r, int _c, int _s, int _d) {
		r = _r, c = _c, speed = _s, dir = _d;
	}
};
 
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
 
bool inb(int r, int c) { return (r >= 1 && r <= n && c >= 1 && c <= m); }
bool ok(int r1, int c1, int r2, int c2) {
	if (r1 == r2) {
		int res = horiz[r1][max(c2,c1)] - horiz[r1][min(c1,c2)-1];
		return (res == 0);
	}
	if (c1 == c2) {
		int res = vert[max(r2,r1)][c2] - vert[min(r2,r1)-1][c2];
		return (res == 0);
	}
	// assert(false);
	return false;
}
 
 
int main() {
 
	scanf(" %d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		for (int j = 1; j <= m; j++)
			grid[i][j] = (s[j-1] - '0');
	}
 
	memset(vert, 0, sizeof(vert));
	memset(horiz, 0, sizeof(horiz));
 
	for (int i = 1; i <= n; i++) {
 
		for (int j = 1; j <= m; j++) {
			vert[i][j] = vert[i-1][j] + grid[i][j];
			horiz[i][j] = horiz[i][j-1] + grid[i][j];
 
		}
 
	}
 
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			for (int k = 0; k < SQRT; k++)
				for (int l = 0; l < 4; l++)
					dp[i][j][k][l] = INF;
 
	queue<state> curr;
	for (int i = 2; i < 3; i++)
		curr.push(state(1,1,0,i)),
		dp[1][1][0][i] = 0;
 
	while (curr.size()) {
 
		state f = curr.front();
		curr.pop();
 
		int r = f.r, c = f.c, sp = f.speed, d = f.dir;
		// assert(grid[r][c] == 0);
 
		if (f.speed == 0) {
			for (int i = 0; i < 4; i++) {
				if (dp[r][c][sp][i] > dp[r][c][sp][d] + 1) {
					dp[r][c][sp][i] = dp[r][c][sp][d] + 1;
					curr.push(state(r, c, sp, i));
				}
			}
		}
 
		if (f.speed > 0) {
			int ns = sp - 1;
			int nr = r + dr[d] * ns;
			int nc = c + dc[d] * ns;
			if (inb(nr, nc) && dp[nr][nc][ns][d] > dp[r][c][sp][d] + 1 && ok(r, c, nr, nc)) {
				dp[nr][nc][ns][d] = dp[r][c][sp][d] + 1;
				curr.push(state(nr, nc, ns, d));
			}
		}
 
		if (sp < SQRT - 1) {
			int ns = sp + 1;
			int nr = r + dr[d] * ns;
			int nc = c + dc[d] * ns;
 
			if (inb(nr, nc) && dp[nr][nc][ns][d] > dp[r][c][sp][d] + 1 && ok(r, c, nr, nc)) {
				dp[nr][nc][ns][d] = dp[r][c][sp][d] + 1;
				curr.push(state(nr, nc, ns, d));
			}
		}
 
 
	}
 
	int ans = INF;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < SQRT; j++)
			ans = min(ans, dp[n][m][j][i]);
	if (ans >= INF) ans = -1;
	printf("%d\n", ans);
 
}
