from typing import List


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        dp = [[0 for _ in range(m)] for _ in range(n)]
        for i in range(n):
            for j in range(m):
                if i - 1 < 0 and j - 1 < 0:
                    dp[i][j] = grid[i][j]
                elif i - 1 < 0:
                    dp[i][j] = grid[i][j] + dp[i][j - 1]
                elif j - 1 < 0:
                    dp[i][j] = grid[i][j] + dp[i - 1][j]
                else:
                    dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1])
        return dp[n - 1][m - 1]
