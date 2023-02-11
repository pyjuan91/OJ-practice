#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		vector<int> shortestAlternatingPaths(
			int n, vector<vector<int>>& redEdges,
			vector<vector<int>>& blueEdges) {
			vector<vector<pair<int, int>>> e(n);
			for (auto edge : redEdges)
				e[edge[0]].push_back({edge[1], 0});
			for (auto edge : blueEdges)
				e[edge[0]].push_back({edge[1], 1});
			queue<pair<int, int>> q;
			queue<int> s;
			q.push({0, -1});
			s.push(0);
			vector<int> res(n, -1);
			vector<vector<bool>> used(n, vector<bool>(2, false));
			used[0][0] = used[0][1] = true;
			while (!q.empty()) {
				int node = q.front().first;
				int lastColor = q.front().second;
				int step = s.front();
				q.pop();
				s.pop();
				if (res[node] == -1) res[node] = step;
				for (auto i : e[node]) {
					if (i.second == lastColor || used[i.first][i.second])
						continue;
					used[i.first][i.second] = true;
					q.push({i.first, i.second});
					s.push(step + 1);
				}
			}
			return res;
		};
};
int main() {
	int n = 5;
	vector<vector<int>> r
		= {{2, 2}, {0, 1}, {0, 3}, {0, 0}, {0, 4},
			 {2, 1}, {2, 0}, {1, 4}, {3, 4}};
	vector<vector<int>> b
		= {{{1, 3}, {0, 0}, {0, 3}, {4, 2}, {1, 0}}};
	Solution s;
	vector<int> res = s.shortestAlternatingPaths(n, r, b);
	for (auto i : res) { cout << i << " "; }
	cout << endl;

	return 0;
}