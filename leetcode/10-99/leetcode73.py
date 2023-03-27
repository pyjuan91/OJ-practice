from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        zero_col = set()
        for i, row in enumerate(matrix):
            hz = False
            for j in range(len(row)):
                if row[j] == 0:
                    hz = True
                    zero_col.add(j)
            if hz:
                matrix[i] = [0] * len(row)

        for i in range(len(matrix)):
            for zc in zero_col:
                matrix[i][zc] = 0
