from typing import List


class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        n, m = len(matrix), len(matrix[0])
        res = 0
        height = [0] * (m + 1)
        for row in range(n):
            for col in range(m):
                height[col] = (height[col] + 1) if matrix[row][col] == "1" else 0
            mono_increasing_stack = [-1]
            for col in range(m + 1):
                while height[col] < height[mono_increasing_stack[-1]]:
                    h = height[mono_increasing_stack.pop()]
                    w = col - mono_increasing_stack[-1] - 1
                    res = max(res, h * w)
                mono_increasing_stack.append(col)
            print(res)
        return res


s = Solution()
s.maximalRectangle(
    matrix=[
        ["1", "0", "1", "0", "0"],
        ["1", "0", "1", "1", "1"],
        ["1", "1", "1", "1", "1"],
        ["1", "0", "0", "1", "0"],
    ]
)

