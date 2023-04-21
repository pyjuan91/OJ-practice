from typing import List
from functools import lru_cache


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        @lru_cache
        def chaewon(top: int) -> int:
            if top <= 1:
                return 0
            return min(
                chaewon(top - 1) + cost[top - 1], chaewon(top - 2) + cost[top - 2]
            )

        return chaewon(len(cost))
