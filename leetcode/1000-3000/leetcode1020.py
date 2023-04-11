from typing import List


class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        res = 0
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]

        def dfs(x: int, y: int) -> int:
            res = 1
            grid[x][y] = 0
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] == 1:
                    res += dfs(x=nx, y=ny)
            return res

        for i in range(n):
            for j in range(m):
                if i == 0 or i == n - 1 or j == 0 or j == m - 1:
                    if grid[i][j] == 1:
                        dfs(x=i, y=j)
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    res += dfs(x=i, y=j)

        return res


s = Solution()
print(s.numEnclaves(grid=[[0, 0, 0, 0], [1, 0, 1, 0], [0, 1, 1, 0], [0, 0, 0, 0]]))
