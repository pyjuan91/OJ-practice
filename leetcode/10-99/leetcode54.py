from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        dir = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        cd = x = y = 0
        m = len(matrix)
        n = len(matrix[0])
        res = []

        for i in range(1, n*m):
            res.append(matrix[x][y])
            matrix[x][y] = 105
            nx = x + dir[cd][0]
            ny = y + dir[cd][1]

            while nx < 0 or nx >= m or ny < 0 or ny >= n or matrix[nx][ny] > 100:
                cd = (cd + 1) % 4
                nx = x + dir[cd][0]
                ny = y + dir[cd][1]

            x, y = nx, ny

        res.append(matrix[x][y])
        return res


s = Solution()
print(s.spiralOrder([[1,2,3,4],[5,6,7,8],[9,10,11,12]]))
