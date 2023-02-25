from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0
        mi = prices[0]
        for price in prices:
            res = max(res, price-mi)
            mi = min(mi, price)
        return res
