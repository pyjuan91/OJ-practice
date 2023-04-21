from typing import List


class Solution:
    def floodFill(
        self, image: List[List[int]], sr: int, sc: int, color: int
    ) -> List[List[int]]:
        org_color = image[sr][sc]
        if org_color == color:
            return image

        n, m = len(image), len(image[0])
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]

        queue = [(sr, sc)]
        while queue:
            cur_row, cur_col = queue.pop(0)
            image[cur_row][cur_col] = color
            for i in range(4):
                nx = cur_row + dx[i]
                ny = cur_col + dy[i]

                if 0 <= nx < n and 0 <= ny < m and image[nx][ny] == org_color:
                    queue.append((nx, ny))

        return image
