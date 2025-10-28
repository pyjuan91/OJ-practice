#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int countCompleteComponents(int n, vector<vector<int>>& edges) {
		vector<vector<bool>> g(n, vector<bool>(n));
		for (const auto& edge : edges) {
			int u = edge[0], v = edge[1];
			g[u][v] = g[v][u] = true;
		}

		vector<bool> vis(n);
		auto dfs = [&](this auto& self, int u) -> vector<int> {
			vector<int> res = {u};
			vis[u] = true;
			for (int i = 0; i < n; i++) {
				if (g[u][i] && !vis[i]) {
					auto child = self(i);
					res.insert(res.end(), child.begin(), child.end());
				}
			}
			return res;
		};

		int res = 0;
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				auto cc = dfs(i);
				bool is_complete = true;
				for (size_t i = 0; i < cc.size(); i++) {
					for (size_t j = i + 1; j < cc.size(); j++) {
						if (!g[cc[i]][cc[j]]) {
							is_complete = false;
						}
					}
				}
				if (is_complete) {
					res++;
				}
			}
		}
		return res;
	}
};

int main() { return 0; }
