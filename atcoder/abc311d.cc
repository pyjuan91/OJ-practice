#include <bits/stdc++.h>
using namespace std;
string g[205];
bool cnt[205][205], cal[205][205][4];
int n, m, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, res = 0;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> g[i];
	auto chaewon = [=](auto x, auto y, auto dir, auto&& chaewon) {
		if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#')
			return;
		if (cal[x][y][dir]) return;
		cal[x][y][dir] = true;
		if (!cnt[x][y]) {
			cnt[x][y] = true;
			res++;
		}
		if (x + dx[dir] >= 0 && y + dy[dir] >= 0 && x + dx[dir] < n && y + dy[dir] < m && g[x + dx[dir]][y + dy[dir]] != '#') {
			chaewon(x + dx[dir], y + dy[dir], dir, chaewon);
		}
		else {
			for (int i = 0; i < 4; i++) {
				if (i == dir) continue;
				chaewon(x, y, i, chaewon);
			}
		}
	};
    chaewon(1, 1, 0, chaewon);
    chaewon(1, 1, 1, chaewon);
    cout << res;
	return 0;
}