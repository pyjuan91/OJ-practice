#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
		vector<vector<int>> g(n);
		vector<int> in_degree(n);
		for (const auto& edge : edges) {
			int u = edge[0], v = edge[1];
			g[u].push_back(v);
			in_degree[v]++;
		}

		vector<set<int>> ancestors(n);
		queue<int> q;

		for (int i = 0; i < n; i++) {
			if (in_degree[i] == 0) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (const auto& v : g[u]) {
				ancestors[v].insert(ancestors[u].begin(), ancestors[u].end());
				ancestors[v].insert(u);
				in_degree[v]--;
				if (in_degree[v] == 0) {
					q.push(v);
				}
			}
		}

		vector<vector<int>> res;
		for (int i = 0; i < n; i++) {
			res.push_back(vector<int>(ancestors[i].begin(), ancestors[i].end()));
		}

        return res;
	}
};

int main() { return 0; }
