#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maximumDetonation(vector<vector<int>>& bombs) {
		int n = bombs.size();

		auto get_dist = [&](int x1, int y1, int x2, int y2) -> double { return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); };

		vector<vector<int>> g(n);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int ux = bombs[i][0];
				int uy = bombs[i][1];
				int urange = bombs[i][2];
				int vx = bombs[j][0];
				int vy = bombs[j][1];
				int vrange = bombs[j][2];

				double dist = get_dist(ux, uy, vx, vy);
				if (dist <= 1.0 * urange) {
					g[i].push_back(j);
				}
				if (dist <= 1.0 * vrange) {
					g[j].push_back(i);
				}
			}
		}

		auto bfs = [&](int denoted_node) -> int {
			queue<int> q;
			vector<bool> bang(n, false);
			q.push(denoted_node);
			bang[denoted_node] = true;

			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (const auto& v : g[u]) {
					if (!bang[v]) {
						q.push(v);
						bang[v] = true;
					}
				}
			}

			return count(bang.begin(), bang.end(), true);
		};

		int res = 0;
		for (int i = 0; i < n; i++) {
			res = max(res, bfs(i));
		}
		return res;
	}
};

int main() { return 0; }
