#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		long long maximumScoreAfterOperations(
		  vector<vector<int>>& edges, vector<int>& values) {
			int n = values.size();
			vector<vector<int>> g(n);
			for (auto& e : edges) {
				g[e[0]].push_back(e[1]);
				g[e[1]].push_back(e[0]);
			}
			vector<long long> subtree_sum(n, 0);
			function<void(int, int)> dfs1 = [&](int u, int p) {
				for (int v : g[u]) {
					if (v == p) continue;
					dfs1(v, u);
					subtree_sum[u] += subtree_sum[v] + values[v];
				}
			};
			dfs1(0, -1);
			function<long long(int, int)> dfs2 = [&](int u, int p) {
				long long subs = 0;
				if (subtree_sum[u] == 0) return 0LL;
				for (int v : g[u]) {
					if (v == p) continue;
					subs += dfs2(v, u);
				}
				return max((long long) values[u] + subs, subtree_sum[u]);
			};
			return dfs2(0, -1);
		}
};
int main() {
	Solution s;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> edges(m, vector<int>(2));
	vector<int> values(n);
	for (int i = 0; i < n; i++) cin >> values[i];
	for (int i = 0; i < m; i++)
		cin >> edges[i][0] >> edges[i][1];
	cout << s.maximumScoreAfterOperations(edges, values) << endl;
	return 0;
}