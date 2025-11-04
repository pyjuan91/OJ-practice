#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> g(numCourses);
		vector<int> in_degree(numCourses);
		vector<bool> vis(numCourses);

		for (const auto& prerequisite : prerequisites) {
			int a = prerequisite[0];
			int b = prerequisite[1];
			g[b].push_back(a);
			in_degree[a]++;
		}

		queue<int> q;
		for (int i = 0; i < numCourses; i++) {
			if (in_degree[i] == 0) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			int u = q.front();
			q.pop();
			vis[u] = true;

			for (const auto& v : g[u]) {
				in_degree[v]--;
				if (in_degree[v] == 0) {
					q.push(v);
				}
			}
		}

		return all_of(vis.begin(), vis.end(), [](bool x) { return x; });
	}
};

int main() { return 0; }
