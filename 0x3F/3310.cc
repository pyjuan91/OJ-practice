#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
		vector<vector<int>> g(n);
		for (const auto& invocation : invocations) {
			int u = invocation[0], v = invocation[1];
			g[u].push_back(v);
		}

		vector<bool> sus(n, false);
		auto dfs1 = [&](this auto& self, int u) -> void {
			sus[u] = true;
			for (const auto& v : g[u]) {
				if (!sus[v]) {
					self(v);
				}
			}
		};
		dfs1(k);

		bool other_spot = false;
		vector<bool> vis(n, false);
		for (int i = 0; i < n; i++) {
			if (!vis[i] && !sus[i]) {
				auto dfs2 = [&](this auto& self, int u) -> bool {
					vis[u] = true;
					for (const auto& v : g[u]) {
						if (sus[v]) {
							return true;
						}
						if (!vis[u] && self(v)) {
							return true;
						}
					}
					return false;
				};
				if (dfs2(i)) {
					other_spot = true;
					break;
				}
			}
		}

		vector<int> res;
		if (other_spot) {
			res.assign(n, 0);
			iota(res.begin(), res.end(), 0);
		} else {
			for (int i = 0; i < n; i++) {
				if (!sus[i]) {
					res.push_back(i);
				}
			}
		}
		return res;
	}
};

int main() { return 0; }
