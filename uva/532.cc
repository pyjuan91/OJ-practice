#include <bits/stdc++.h>
using namespace std;
string g[31][31];
int vist[31][31][31];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m;
	while (cin >> t >> n >> m && t) {
		for (int i = 0; i < t; i++) {
			for (int j = 0; j < n; j++) cin >> g[i][j];
		}
		auto find_certain = [&](char c) {
			for (int i = 0; i < t; i++)
				for (int j = 0; j < n; j++)
					for (int k = 0; k < m; k++)
						if (g[i][j][k] == c)
							return make_tuple(i, j, k);
            return make_tuple(-1, -1, -1);
		};
		memset(vist, 0, sizeof(vist));
		int sx, sy, sz;
		tie(sx, sy, sz) = find_certain('S');
		const int dx[] = {0, 0, 0, 0, 1, -1};
		const int dy[] = {0, 0, 1, -1, 0, 0};
		const int dz[] = {1, -1, 0, 0, 0, 0};
		auto is_valid = [&](int x, int y, int z) {
			return x >= 0 && x < t && y >= 0 && y < n && z >= 0
				&& z < m && g[x][y][z] != '#' && !vist[x][y][z];
		};
		queue<tuple<int, int, int>> q;
		queue<int> dis;
		q.emplace(sx, sy, sz);
		dis.emplace(0);
		vist[sx][sy][sz] = 1;
		while (!q.empty()) {
			int x, y, z;
			tie(x, y, z) = q.front(), q.pop();
			int d = dis.front();
			dis.pop();
			if (g[x][y][z] == 'E') {
				cout << "Escaped in " << d << " minute(s).\n";
				goto end;
			}
			for (int i = 0; i < 6; i++) {
				int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
				if (is_valid(nx, ny, nz)) {
					q.emplace(nx, ny, nz);
					dis.emplace(d + 1);
					vist[nx][ny][nz] = 1;
				}
			}
		}
		cout << "Trapped!\n";
	end:;
	}
	return 0;
}
