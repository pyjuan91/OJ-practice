#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Node {
		int cost, cur, tar;
		Node(int cost, int cur, int tar)
		  : cost(cost)
		  , cur(cur)
		  , tar(tar) {}
		Node()
		  : cost(0)
		  , cur(0)
		  , tar(0) {}
};
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, u, v, oo = 0;
	cin >> n;
	vector<vector<int>> g(n + 1);
	vector<Node> nodes(n + 1);
	vector<int> accu_one(n + 1), accu_zero(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> nodes[i].cost >> nodes[i].cur >> nodes[i].tar;
		oo = oo + nodes[i].cur - nodes[i].tar;
	}
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	if (oo != 0) {
		cout << -1 << '\n';
		return 0;
	}
	function<void(int, int, int)> dfs
	  = [&](int cur, int prev, int min_cost) {
		min_cost = min(min_cost, nodes[cur].cost);
		if (nodes[cur].cur == 1 && nodes[cur].tar == 0)
			accu_one[cur]++;
		if (nodes[cur].cur == 0 && nodes[cur].tar == 1)
			accu_zero[cur]++;
		for (auto nxt : g[cur]) {
			if (nxt != prev) {
				dfs(nxt, cur, min_cost);
				accu_one[cur] += accu_one[nxt];
				accu_zero[cur] += accu_zero[nxt];
			}
		}
		int done_on_this_level = min(accu_one[cur], accu_zero[cur]);
		oo += 2 * min_cost * done_on_this_level;
		accu_one[cur] -= done_on_this_level;
		accu_zero[cur] -= done_on_this_level;
	};
	dfs(1, 0, 1e18);
	cout << oo << '\n';
	return 0;
}
