from typing import List


class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        dp = [0] + [1e18] * 365
        for day in range(1, 366):
            if day in days:
                dp[day] = min(
                    dp[max(day - 1, 0)] + costs[0],
                    dp[max(day - 7, 0)] + costs[1],
                    dp[max(day - 30, 0)] + costs[2],
                )
            else:
                dp[day] = dp[day - 1]
        return dp[365]

