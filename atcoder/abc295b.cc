#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int r, c;
	cin >> r >> c;
	vector<string> g(r);
	vector<vector<int>> bomb;
	for (int i = 0; i < r; i++) cin >> g[i];
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (g[i][j] >= '1' && g[i][j] <= '9')
				bomb.push_back({i, j, g[i][j] - '0'});
	for (auto b : bomb) {
		auto x = b[0], y = b[1], power = b[2];
		for (int i = 0; i <= power; i++) {
			for (int j = 0; j + i <= power; j++) {
				int nx = x + i, ny = y + j;
				if (nx >= 0 && nx < r && ny >= 0 && ny < c)
					g[nx][ny] = '.';
				nx = x - i;
				if (nx >= 0 && nx < r && ny >= 0 && ny < c)
					g[nx][ny] = '.';
				ny = y - j;
				if (nx >= 0 && nx < r && ny >= 0 && ny < c)
					g[nx][ny] = '.';
				nx = x + i;
				if (nx >= 0 && nx < r && ny >= 0 && ny < c)
					g[nx][ny] = '.';
			}
		}
	}
	for (auto s : g) cout << s << "\n";
	return 0;
}