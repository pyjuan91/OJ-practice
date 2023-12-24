#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		void solve(vector<vector<char>>& board) {
			int n = board.size(), m = board[0].size();
			auto on_border = [&](int i, int j) {
				return i == 0 || j == 0 || i == n - 1 || j == m - 1;
			};
			vector<vector<bool>> vis(n, vector<bool>(m, false));
			const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
			function<void(int, int, bool&)> dfs
			  = [&](int i, int j, bool& dont_flip) {
				vis[i][j] = true;
				if (on_border(i, j)) dont_flip = true;
				for (int k = 0; k < 4; ++k) {
					int x = i + dx[k], y = j + dy[k];
					if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || board[x][y] == 'X')
						continue;
					dfs(x, y, dont_flip);
				}
			};
			function<void(int, int, char)> fill
			  = [&](int i, int j, char c) {
				board[i][j] = c;
				for (int k = 0; k < 4; ++k) {
					int x = i + dx[k], y = j + dy[k];
					if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O')
						continue;
					fill(x, y, c);
				}
			};
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (!vis[i][j] && board[i][j] == 'O') {
						bool dont_flip = false;
						dfs(i, j, dont_flip);
						if (!dont_flip) fill(i, j, 'X');
					}
				}
			}
		}
};
int main() { return 0; }