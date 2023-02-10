#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		const int dx[4] = {1, -1, 0, 0};
		const int dy[4] = {0, 0, 1, -1};
		int maxDistance(vector<vector<int>>& grid) {
			int n = grid.size(), cs;
			queue<pair<int, int>> q;
			queue<int> step;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (grid[i][j] == 1) {
						q.push({i, j});
						step.push(0);
					}
				}
			}
			if (step.empty() || step.size() == n * n)
				return -1;
			while (!q.empty()) {
				pair<int, int> cp = q.front();
				cs = step.front();
				q.pop();
				step.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cp.first + dx[i];
					int ny = cp.second + dy[i];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n || grid[nx][ny] == 1)
						continue;
					grid[nx][ny] = 1;
					q.push({nx, ny});
					step.push(cs + 1);
				}
			}
			return cs;
		}
};
int main() { return 0; }