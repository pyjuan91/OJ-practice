#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
		vector<vector<int>> g(n);
		for (int i = 0; i < n - 1; i++) {
			g[i].push_back(i + 1);
		}
		vector<int> res;
		for (const auto& query : queries) {
			int u = query[0], v = query[1];
			g[u].push_back(v);
			auto bfs = [&]() -> int {
				queue<int> q, d;
				vector<bool> vis(n);
				q.push(0), d.push(0);
				while (!q.empty()) {
					int u = q.front();
					int x = d.front();
                    q.pop();
                    d.pop();
					vis[u] = true;
					if (u == n - 1) {
						return x;
					}
					for (const auto& v : g[u]) {
						if (vis[v]) {
							continue;
						}
						q.push(v);
						d.push(x + 1);
					}
				}
				return 0;
			};
			res.push_back(bfs());
		}
		return res;
	}
};

int main() { return 0; }
