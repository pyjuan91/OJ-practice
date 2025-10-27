#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long countPairs(int n, vector<vector<int>>& edges) {
		vector<vector<int>> g(n);
		for (const auto& edge : edges) {
			int u = edge[0], v = edge[1];
			g[u].push_back(v);
			g[v].push_back(u);
		}

		vector<int> cc;
		vector<bool> vis(n);
		auto dfs = [&](this auto& self, int u) -> int {
			int res = 1;
			vis[u] = true;
			for (const auto& v : g[u]) {
				if (!vis[v]) {
					res += self(v);
				}
			}
			return res;
		};

		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				cc.push_back(dfs(i));
			}
		}

		int m = cc.size();
		vector<long long> prefix(m + 1);
		for (int i = 1; i <= m; i++) {
			prefix[i] = prefix[i - 1] + cc[i - 1];
		}

		long long res = 0;
		for (int i = 1; i < m; i++) {
			res += cc[i] * prefix[i];
		}

		return res;
	}
};

int main() { return 0; }
