#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minScore(int n, vector<vector<int>>& roads) {
		vector<vector<pair<int, int>>> g(n + 1);
		for (const auto& road : roads) {
			int u = road[0], v = road[1], w = road[2];
			g[u].push_back(make_pair(v, w));
			g[v].push_back(make_pair(u, w));
		}

		int res = numeric_limits<int>::max();
		vector<bool> vis(n + 1, false);
		auto dfs = [&](this auto& self, int u) -> void {
			vis[u] = true;
			for (const auto& [v, w] : g[u]) {
				res = min(res, w);
				if (!vis[v]) {
					self(v);
				}
			}
		};
		dfs(1);

		return res;
	}
};

int main() { return 0; }
