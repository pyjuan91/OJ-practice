#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, k, a, b;
	cin >> n >> m >> k;
	set<pair<int, int>> s, vis;
	while (k--) {
		cin >> a >> b;
		s.insert(make_pair(a, b));
	}
	int res[10] = {(n - 2) * (m - 2)};
	const pair<int, int> d[9]
	  = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0},
		 {0, 1},   {1, -1}, {1, 0},  {1, 1}};
	for (auto p : s) {
		int x = p.first, y = p.second;
		for (int i = 0; i < 9; i++) {
			int ix = x + d[i].first, iy = y + d[i].second;
			if (ix < 2 || ix > n - 1 || iy < 2 || iy > m - 1)
				continue;
			if (vis.count(make_pair(ix, iy))) continue;
			vis.insert(make_pair(ix, iy));
			int cnt = 0;
			for (int j = 0; j < 9; j++) {
				int jx = ix + d[j].first, jy = iy + d[j].second;
				if (jx < 1 || jx > n || jy < 1 || jy > m)
					continue;
				if (s.count(make_pair(jx, jy))) cnt++;
			}
			res[cnt]++;
			res[0]--;
		}
	}
    for (int i = 0; i < 10; i++) cout << res[i] << '\n';
	return 0;
}
