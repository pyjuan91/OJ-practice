#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		int n = graph.size();
		// -1: unvisited, 0: visited, 1: safe, 2: unsafe
		vector<int> states(n, -1);

		auto dfs = [&](this auto& self, int u) -> int {
			if (states[u] == -1) {
				states[u] = 0;
				bool is_safe = true;
				for (const auto& v : graph[u]) {
					if (self(v) != 1) {
						is_safe = false;
					}
				}
				if (is_safe) {
					states[u] = 1;
				} else {
					states[u] = 2;
				}
				return states[u];
			}
			if (states[u] == 0) {
				return states[u] = 2;
			}
			return states[u];
		};

		for (int i = 0; i < n; i++) {
			if (states[i] == -1) {
				dfs(i);
			}
		}

		vector<int> res;
		for (int i = 0; i < n; i++) {
			if (states[i] == 1) {
				res.push_back(i);
			}
		}

		return res;
	}
};

int main() { return 0; }
