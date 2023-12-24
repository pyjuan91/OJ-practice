#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int n, q, a, b;
	cin >> n >> q;
	vector<vector<int>> g(n + 1, vector<int>(20, 0));
	vector<int> depth(n + 1, 0);

	for (int i = 2; i <= n; i++) cin >> g[i][0];

	for (int bi_jump = 1; bi_jump < 20; bi_jump++) {
		for (int node = 2; node <= n; node++) {
			g[node][bi_jump] = g[g[node][bi_jump - 1]][bi_jump - 1];
		}
	}

	function<int(int)> get_depth = [&](int node) {
		if (depth[node] != 0) return depth[node];
		if (node == 1) return depth[node] = 1;
		return depth[node] = 1 + get_depth(g[node][0]);
	};

	while (q--) {
		cin >> a >> b;
		int depth_a = get_depth(a), depth_b = get_depth(b);
		if (depth_a > depth_b)
			swap(a, b), swap(depth_a, depth_b);
		depth_b -= depth_a;
		for (int bi_jump = 0; bi_jump < 20; bi_jump++) {
			if (depth_b & (1 << bi_jump)) b = g[b][bi_jump];
		}
		if (a == b) {
			cout << a << "\n";
			continue;
		}
		for (int bi_jump = 19; bi_jump >= 0; bi_jump--) {
			if (g[a][bi_jump] != g[b][bi_jump]) {
				a = g[a][bi_jump];
				b = g[b][bi_jump];
			}
		}
        cout << g[a][0] << "\n";
	}

	return 0;
}
