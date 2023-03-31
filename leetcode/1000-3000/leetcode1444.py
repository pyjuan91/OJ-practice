from typing import List
from functools import lru_cache


class Solution:
    def ways(self, pizza: List[str], K: int) -> int:
        N, M = len(pizza), len(pizza[0])
        MOD = int(1e9 + 7)

        prefix_sum = [[0] * (M + 1) for _ in range(N + 1)]
        for i in range(N - 1, -1, -1):
            for j in range(M - 1, -1, -1):
                prefix_sum[i][j] += int(pizza[i][j] == "A")
                prefix_sum[i][j] += (
                    prefix_sum[i + 1][j]
                    + prefix_sum[i][j + 1]
                    - prefix_sum[i + 1][j + 1]
                )

        # dp = [[[-1] * (K + 1) for _ in range(M + 1)] for _ in range(N + 1)]

        @lru_cache(maxsize=2**15)
        def chaewon(cur_row: int, cur_col: int, remain_cut: int) -> int:
            if prefix_sum[cur_row][cur_col] == 0:
                return 0
            if remain_cut == 0:
                return 1
            # if dp[cur_row][cur_col][remain_cut] >= 0:
            #     return dp[cur_row][cur_col][remain_cut]
            res = 0

            for i in range(cur_row + 1, N):
                if prefix_sum[cur_row][cur_col] - prefix_sum[i][cur_col] > 0:
                    res += chaewon(i, cur_col, remain_cut - 1)
                    res %= MOD
            for j in range(cur_col + 1, M):
                if prefix_sum[cur_row][cur_col] - prefix_sum[cur_row][j] > 0:
                    res += chaewon(cur_row, j, remain_cut - 1)
                    res %= MOD

            # dp[cur_row][cur_col][remain_cut] = res
            return res

        return chaewon(0, 0, K - 1)


s = Solution()
print(s.ways(pizza=["A..", "AAA", "..."], K=3))
