#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]=='1') {
                    ans++;
                    anya(grid, m, n, i, j);
                }
            }
        }
        return ans;
    }
    void anya(vector<vector<char>>& grid, int m, int n, int sr, int sc)
    {
        grid[sr][sc] = '0';
        if (sr + 1 < m && grid[sr + 1][sc]=='1') {
            anya(grid, m, n, sr + 1, sc);
        }
        if (sr - 1 >= 0 && grid[sr - 1][sc]=='1') {
            anya(grid, m, n, sr - 1, sc);
        }
        if (sc + 1 < n && grid[sr][sc + 1]=='1') {
            anya(grid, m, n, sr, sc + 1);
        }
        if (sc - 1 >= 0 && grid[sr][sc - 1]=='1') {
            anya(grid, m, n, sr, sc - 1);
        }
    }
};
int main(void)
{
    Solution s;
    vector<vector<int>> grid;
    vector<int> entry;
    entry.push_back(1);
    return 0;
}