from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]

        n, m = len(grid), len(grid[0])
        res = 0

        def chaewon(x, y):
            grid[x][y] = "0"
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] == "1":
                    chaewon(nx, ny)

        for i in range(n):
            for j in range(m):
                if grid[i][j] == "1":
                    res += 1
                    chaewon(i, j)

        return res
