#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
    int res = 0;
    void dfs(vector<vector<int>>& g, int tar, int cur,
        int x, int y, vector<vector<bool>>& used, int n, int m)
    {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n
                || ny < 0 || ny >= m
                || used[nx][ny] || g[nx][ny] == -1)
                continue;
            used[nx][ny] = true;
            if (g[nx][ny] == 2) {
                if (cur == tar)
                    res += 1;
            } else {
                dfs(g, tar, cur + 1, nx, ny, used, n, m);
            }
            used[nx][ny] = false;
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size(), tar = 0;
        pair<int, int> start, end;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0)
                    tar++;
                else if (grid[i][j] == 1)
                    start = make_pair(i, j);
                else if (grid[i][j] == 2)
                    end = make_pair(i, j);
            }
        }

        vector<vector<bool>> used(n, vector<bool>(m, false));
        used[start.first][start.second] = true;
        dfs(grid, tar, 0, start.first, start.second, used, n, m);
        return res;
    }
};
int main(void) { return 0; }