from typing import List


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        n, m = len(obstacleGrid), len(obstacleGrid[0])
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        dp[1][1] = int(obstacleGrid[0][0] == 0)
        for i in range(n):
            for j in range(m):
                if obstacleGrid[i][j] == 0:
                    dp[i+1][j+1] += dp[i][j+1] + dp[i+1][j]
        return dp[n][m]
