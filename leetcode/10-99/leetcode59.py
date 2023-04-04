from typing import List


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res = [[0] * n for _ in range(n)]
        x = y = dir = 0
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        for i in range(n * n):
            res[x][y] = i + 1
            nx = x + dx[dir]
            ny = y + dy[dir]
            if nx < 0 or nx >= n or ny < 0 or ny >= n or res[nx][ny] != 0:
                dir = (dir + 1) % 4
                nx = x + dx[dir]
                ny = y + dy[dir]
            x = nx
            y = ny
        return res


s = Solution()
print(s.generateMatrix(n=3))
