#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int N, M, sx, sy, ex, ey;
char g[2005][2005];
bool after[2005][2005], vis[2005][2005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> g[i][j], after[i][j] = true;
			if (g[i][j] == 'S') sx = i, sy = j;
			if (g[i][j] == 'G') ex = i, ey = j;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (g[i][j] == '#') after[i][j] = false;
			else if (g[i][j] == '^') {
				after[i][j] = false;
				for (int k = i - 1; k >= 1 && g[k][j] == '.'; k--)
					after[k][j] = false;
			}
			else if (g[i][j] == 'v') {
				after[i][j] = false;
				for (int k = i + 1; k <= N && g[k][j] == '.'; k++)
					after[k][j] = false;
			}
			else if (g[i][j] == '>') {
				after[i][j] = false;
				for (int k = j + 1; k <= M && g[i][k] == '.'; k++)
					after[i][k] = false;
			}
			else if (g[i][j] == '<') {
				after[i][j] = false;
				for (int k = j - 1; k >= 1 && g[i][k] == '.'; k--)
					after[i][k] = false;
			}
		}
	}
	if (after[ex][ey] == false || after[sx][sy] == false) {
		cout << -1 << '\n';
		return 0;
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) vis[i][j] = false;
	queue<int> x, y, d;
	x.push(sx), y.push(sy), d.push(0);
	vis[sx][sy] = true;
	while (!x.empty()) {
		int cur_x = x.front(), cur_y = y.front(), cur_d = d.front();
		x.pop(), y.pop(), d.pop();
		if (cur_x == ex && cur_y == ey) {
			cout << cur_d << "\n";
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i], ny = cur_y + dy[i];
			if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
			if (vis[nx][ny] || after[nx][ny] == false) continue;
			vis[nx][ny] = true;
			x.push(nx), y.push(ny), d.push(cur_d + 1);
		}
	}
	cout << "-1\n";
	return 0;
}
