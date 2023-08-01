#include <iostream>
#include <string>
#define ROW 5
#define COL 5
using namespace std;

int main() {
	int kase = 1;
	while (true) {
		char puzzle[ROW][COL];
		string str, moves;
		int isBreak = 0, isFail = 0, blank_row = 0, blank_col = 0;
		// 读取迷宫
		for (int i = 0; i < ROW; i++) {
			getline(cin, str);
			if (str[0] == 'Z') {
				isBreak = 1;
				break;
			}

			for (int j = 0; j < COL; j++) {
				puzzle[i][j] = str[j];
				if (str[j] == ' ') { // 记录空格位置
					blank_row = i;
					blank_col = j;
				}
			}
		}
		if (isBreak) break;

		// 读取移动操作
		do { // 考虑到 moves 可能分为多行的情况
			string subMoves;
			getline(cin, subMoves);
			moves += subMoves;
		} while (moves[moves.length() - 1] != '0');

		for (int i = 0; i < moves.length(); i++) {
			if (moves[i] == 'A') {
				if (blank_row - 1 < 0) {
					isFail = 1;
					break;
				}
				else {
					char tmp = puzzle[blank_row - 1][blank_col];
					puzzle[blank_row - 1][blank_col]
					  = puzzle[blank_row][blank_col];
					puzzle[blank_row][blank_col] = tmp;
					blank_row--; // 更新空白区域的位置
				}
			}
			if (moves[i] == 'B') {
				if (blank_row + 1 > 4) {
					isFail = 1;
					break;
				}
				else {
					char tmp = puzzle[blank_row + 1][blank_col];
					puzzle[blank_row + 1][blank_col]
					  = puzzle[blank_row][blank_col];
					puzzle[blank_row][blank_col] = tmp;
					blank_row++;
				}
			}
			if (moves[i] == 'L') {
				if (blank_col - 1 < 0) {
					isFail = 1;
					break;
				}
				else {
					char tmp = puzzle[blank_row][blank_col - 1];
					puzzle[blank_row][blank_col - 1]
					  = puzzle[blank_row][blank_col];
					puzzle[blank_row][blank_col] = tmp;
					blank_col--;
				}
			}
			if (moves[i] == 'R') {
				if (blank_col + 1 > 4) {
					isFail = 1;
					break;
				}
				else {
					char tmp = puzzle[blank_row][blank_col + 1];
					puzzle[blank_row][blank_col + 1]
					  = puzzle[blank_row][blank_col];
					puzzle[blank_row][blank_col] = tmp;
					blank_col++;
				}
			}
			if (moves[i] == '0') break;
		}

		if (kase >= 2) cout << endl;
		cout << "Puzzle #" << kase++ << ":\n";
		if (isFail)
			cout << "This puzzle has no final configuration.\n";
		else {
			for (int i = 0; i < ROW; i++) {
				for (int j = 0; j < COL - 1; j++)
					cout << puzzle[i][j] << ' ';
				cout << puzzle[i][COL - 1] << endl;
			}
		}
	}
	return 0;
}