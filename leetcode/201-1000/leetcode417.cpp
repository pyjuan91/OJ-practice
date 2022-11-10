#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    const int maxn = 205;
    int m, n, pacific[205][205], atlan[205][205];
    vector<vector<int>> res;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        for (int i = 0; i < maxn; i++) {
            for (int j = 0; j < maxn; j++) {
                pacific[i][j] = atlan[i][j] = 0;
            }
        }
        res.clear();
        if (heights.size() == 0 || heights[0].size() == 0)
            return res;
        m = heights.size(), n = heights[0].size();
        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlan, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlan, m - 1, j);
        }
        return res;
    }

    void dfs(vector<vector<int>>& h, int vis[][205], int i, int j)
    {
        if (vis[i][j])
            return;
        vis[i][j] = 1;
        if (pacific[i][j] && atlan[i][j]) {
            res.push_back({ i, j });
        }
        if (i < m - 1 && h[i][j] <= h[i + 1][j]) {
            dfs(h, vis, i + 1, j);
        }
        if (j < n - 1 && h[i][j] <= h[i][j + 1]) {
            dfs(h, vis, i, j + 1);
        }
        if (i > 0 && h[i][j] <= h[i - 1][j]) {
            dfs(h, vis, i - 1, j);
        }
        if (j > 0 && h[i][j] <= h[i][j - 1]) {
            dfs(h, vis, i, j - 1);
        }
    }
};
int main(void) { return 0; }