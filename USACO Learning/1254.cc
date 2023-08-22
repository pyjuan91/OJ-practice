#include <bits/stdc++.h>
#define int long long
using namespace std;
int child_remain(int cur, int prev, auto& a, auto& g, auto& out, auto& in) {
	int this_quota = a[cur];
	for (auto child : g[cur]) {
		if (child == prev) continue;
		int child_quota = child_remain(child, cur, a, g, out, in);
		this_quota += child_quota;
		if (child_quota > 0) {
			in[cur].emplace_back(child);
			out[child].emplace_back(cur, child_quota);
		}
		else if (child_quota < 0) {
			in[child].emplace_back(cur);
			out[cur].emplace_back(child, -child_quota);
		}
	}
	return this_quota;
}
void gen_route(int node, auto& completed, auto& res, auto& out, auto& in) {
	if (completed[node]) return;
	completed[node] = true;
	for (auto child : in[node])
		gen_route(child, completed, res, out, in);
	for (auto [child, quota] : out[node])
		res.emplace_back(vector<int> {node, child, quota});
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, su = 0, u, v;
	cin >> n;
	vector<int> a(n + 1);
	vector<vector<int>> g(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		su += a[i];
	}
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	su /= n;
	for (int i = 1; i <= n; i++) a[i] -= su;
	vector<vector<int>> in(n + 1);
	vector<vector<pair<int, int>>> out(n + 1);
	child_remain(1, 0, a, g, out, in);
	vector<bool> completed(n + 1, false);
	vector<vector<int>> res;
	for (int i = 1; i <= n; i++)
		gen_route(i, completed, res, out, in);
	cout << res.size() << '\n';
	for (auto& route : res)
		cout << route[0] << ' ' << route[1] << ' ' << route[2] << '\n';
	return 0;
}
