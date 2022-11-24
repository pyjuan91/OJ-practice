#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> vis(n, vector<bool>(m, false));
                    vis[i][j] = true;
                    if (dfs(board, word, 1, vis, n, m, i, j))
                        return true;
                    vis[i][j] = false;
                }
            }
        }
        return false;
    }

    const int dx[4] = { 0, 0, 1, -1 };
    const int dy[4] = { 1, -1, 0, 0 };
    bool dfs(vector<vector<char>>& board, string word,
        int pos, vector<vector<bool>>& vis,
        int n, int m, int curx, int cury)
    {
        if (pos >= word.length())
            return true;
        for (int i = 0; i < 4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m
                && !vis[nx][ny] && board[nx][ny] == word[pos]) {
                vis[nx][ny] = true;
                if (dfs(board, word, pos + 1, vis, n, m, nx, ny))
                    return true;
                vis[nx][ny] = false;
            }
        }
        return false;
    }
};
int main(void) { return 0; }