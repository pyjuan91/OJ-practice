#include <bits/stdc++.h>
using namespace std;
int t, cap_a, cap_b, cap_c, d;
queue<int> a, b, c, pour;
int vis[201][201][201], ans[201];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> cap_a >> cap_b >> cap_c >> d;
		for (int i = 0; i <= cap_a; i++)
			for (int j = 0; j <= cap_b; j++)
				for (int k = 0; k <= cap_c; k++)
					vis[i][j][k] = INT32_MAX;
		for (int i = 0; i <= d; i++) ans[i] = INT32_MAX;
		a.push(0), b.push(0), c.push(cap_c), pour.push(0);
		auto chaewon = [&](int x, int y, int z, int p) {
			a.push(x), b.push(y), c.push(z), pour.push(p);
		};
		while (!a.empty()) {
			int x = a.front(), y = b.front(), z = c.front(),
				p = pour.front();
			a.pop(), b.pop(), c.pop(), pour.pop();
			if (p >= ans[d]) continue;
			if (vis[x][y][z] <= p) continue;
			vis[x][y][z] = p;
			ans[x] = min(ans[x], p);
			ans[y] = min(ans[y], p);
			ans[z] = min(ans[z], p);
			if (x) {
				if (x <= cap_b - y) chaewon(0, x + y, z, p + x);
				else
					chaewon(x - (cap_b - y), cap_b, z, p + cap_b - y);
				if (x <= cap_c - z) chaewon(0, y, x + z, p + x);
				else
					chaewon(x - (cap_c - z), y, cap_c, p + cap_c - z);
			}
			if (y) {
				if (y <= cap_a - x) chaewon(x + y, 0, z, p + y);
				else
					chaewon(cap_a, y - (cap_a - x), z, p + cap_a - x);
				if (y <= cap_c - z) chaewon(x, 0, y + z, p + y);
				else
					chaewon(x, y - (cap_c - z), cap_c, p + cap_c - z);
			}
			if (z) {
				if (z <= cap_a - x) chaewon(x + z, y, 0, p + z);
				else
					chaewon(cap_a, y, z - (cap_a - x), p + cap_a - x);
				if (z <= cap_b - y) chaewon(x, y + z, 0, p + z);
				else
					chaewon(x, cap_b, z - (cap_b - y), p + cap_b - y);
			}
		}
		for (int i = d; i >= 0; i--) {
			if (ans[i] != INT32_MAX) {
				cout << ans[i] << ' ' << i << '\n';
				break;
			}
		}
	}
	return 0;
}