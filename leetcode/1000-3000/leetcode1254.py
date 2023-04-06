from typing import List


class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]
        n = len(grid)
        m = len(grid[0])
        res = 0

        def dfs(x: int, y: int) -> None:
            if grid[x][y] == 1:
                return
            grid[x][y] = 1
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if 0 <= nx < n and 0 <= ny < m:
                    dfs(x=nx, y=ny)

        for i in range(n):
            for j in range(m):
                if (i == 0 or i == n - 1 or j == 0 or j == m - 1) and grid[i][j] == 0:
                    dfs(x=i, y=j)
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 0:
                    dfs(x=i, y=j)
                    res += 1

        return res


s = Solution()
print(
    s.closedIsland(
        grid=[
            [1, 1, 1, 1, 1, 1, 1],
            [1, 0, 0, 0, 0, 0, 1],
            [1, 0, 1, 1, 1, 0, 1],
            [1, 0, 1, 0, 1, 0, 1],
            [1, 0, 1, 1, 1, 0, 1],
            [1, 0, 0, 0, 0, 0, 1],
            [1, 1, 1, 1, 1, 1, 1],
        ]
    )
)
