#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		bool sol = false;
		bool valid(vector<vector<char>>& b) {
			// check horizontal
			for (int i = 0; i < 9; i++) {
				vector<bool> a(10, false);
				for (int j = 0; j < 9; j++) {
					if (b[i][j] == '.') continue;
					if (a[b[i][j] - '0']) return false;
					a[b[i][j] - '0'] = true;
				}
			}
			// check vertical
			for (int i = 0; i < 9; i++) {
				vector<bool> a(10, false);
				for (int j = 0; j < 9; j++) {
					if (b[j][i] == '.') continue;
					if (a[b[j][i] - '0']) return false;
					a[b[j][i] - '0'] = true;
				}
			}
			// check block
			for (int i = 0; i < 9; i += 3) {
				for (int j = 0; j < 9; j += 3) {
					if (!checkBlock(b, i, j)) return false;
				}
			}
			return true;
		}
		bool checkBlock(vector<vector<char>>& b, int tlx, int tly) {
			vector<bool> a(10, false);
			for (int i = tlx; i < tlx + 3; i++) {
				for (int j = tly; j < tly + 3; j++) {
					if (b[i][j] == '.') continue;
					if (a[b[i][j] - '0']) return false;
					a[b[i][j] - '0'] = true;
				}
			}
			return true;
		}
		void solveSudoku(vector<vector<char>>& board) {
			vector<pair<int, int>> dot;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (board[i][j] == '.')
						dot.emplace_back(make_pair(i, j));
				}
			}
			chaewon(board, 0, dot);
		}
		void chaewon(
			vector<vector<char>>& b, int cur,
			vector<pair<int, int>>& dot) {
			if (cur == dot.size()) {
				sol = true;
				return;
			}
			for (int i = 1; i <= 9; i++) {
				char c = ('0' + i);
				b[dot[cur].first][dot[cur].second] = c;
				if (valid(b)) {
					chaewon(b, cur + 1, dot);
				}
				if (sol) return;
				b[dot[cur].first][dot[cur].second] = '.';
			}
		}
};
int main() {
	vector<vector<char>> board {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'},
	};
	auto s = Solution();
	s.solveSudoku(board);
	for (auto i : board) {
		for (auto j : i) cout << j;
		cout << endl;
	}
	return 0;
}