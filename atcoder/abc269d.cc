#include <bits/stdc++.h>
using namespace std;
int N, x, y, res = 0;
bool g[2005][2005];
void chaewon(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	g[x][y] = false;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x - 1 >= 0) {
			if (y - 1 >= 0 && g[x - 1][y - 1]) {
				g[x - 1][y - 1] = false;
				q.push(make_pair(x - 1, y - 1));
			}
			if (g[x - 1][y]) {
				g[x - 1][y] = false;
				q.push(make_pair(x - 1, y));
			}
		}
		if (y - 1 >= 0 && g[x][y - 1]) {
			g[x][y - 1] = false;
			q.push(make_pair(x, y - 1));
		}
		if (y + 1 < 2005 && g[x][y + 1]) {
			g[x][y + 1] = false;
			q.push(make_pair(x, y + 1));
		}
		if (x + 1 < 2005) {
			if (g[x + 1][y]) {
				g[x + 1][y] = false;
				q.push(make_pair(x + 1, y));
			}
			if (y + 1 < 2005 && g[x + 1][y + 1]) {
				g[x + 1][y + 1] = false;
				q.push(make_pair(x + 1, y + 1));
			}
		}
	}
}
int main() {
	cin.tie()->sync_with_stdio(false);
	cin >> N;
	vector<pair<int, int>> a;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		x += 1000;
		y += 1000;
		a.emplace_back(make_pair(x, y));
		g[x][y] = true;
	}
	for (int i = 0; i < N; i++) {
		x = a[i].first;
		y = a[i].second;
		if (g[x][y]) {
			res += 1;
			chaewon(x, y);
		}
	}
	cout << res;
	return 0;
}