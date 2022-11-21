#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++) {
            vector<bool> used(10, false);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                if (used[board[i][j] - '0'])
                    return false;
                used[board[i][j] - '0'] = true;
            }
        }
        for (int i = 0; i < 9; i++) {
            vector<bool> used(10, false);
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.')
                    continue;
                if (used[board[j][i] - '0'])
                    return false;
                used[board[j][i] - '0'] = true;
            }
        }
        for (int i = 0; i < 9; i++) {
            vector<bool> used(10, false);
            for (int j = 0; j < 9; j++) {
                // cout << (i / 3) * 3 + j / 3 << " " << j % 3 + (i % 3) * 3 << endl;
                char c = board[(i / 3) * 3 + j / 3][j % 3 + (i % 3) * 3];
                if (c == '.')
                    continue;
                if (used[c - '0']) {
                    // cout << i / 3 + j / 3 << " " << j % 3 + (i % 3) * 3 << endl;
                    // cout << board[i / 3 + j / 3][j % 3 + (i % 3) * 3] << endl;
                    return false;
                }
                used[c - '0'] = true;

                // cout << i / 3 + j / 3 << " " << j % 3 + (i % 3) * 3 << endl;
            }
            // cout << endl;
        }
        return true;
    }
};
int main(void)
{
    vector<vector<char>> v = { { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' } };
    Solution s;
    cout << s.isValidSudoku(v);
    return 0;
}