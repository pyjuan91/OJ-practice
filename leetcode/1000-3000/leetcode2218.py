from typing import List
from functools import lru_cache


class Solution:
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        @lru_cache(None)
        def chaewon(cur_pile: int, remaining_step: int) -> int:
            if remaining_step == 0 or cur_pile == len(piles):
                return 0
            res = chaewon(cur_pile + 1, remaining_step)
            prev = 0
            for i in range(len(piles[cur_pile])):
                if remaining_step - i - 1 < 0:
                    break
                prev += piles[cur_pile][i]
                res = max(res, prev + chaewon(cur_pile + 1, remaining_step - i - 1))
            return res

        return chaewon(0, k)


s = Solution()
print(s.maxValueOfCoins(piles=[[1, 100, 3], [7, 8, 9]], k=2))
print(
    s.maxValueOfCoins(
        piles=[[100], [100], [100], [100], [100], [100], [1, 1, 1, 1, 1, 1, 700]], k=7
    )
)
