from typing import List


class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        return [candy + extraCandies >= max(candies) for candy in candies]
