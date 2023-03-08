from typing import List


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def chaewon(guess: int) -> bool:
            res = 0
            for pile in piles:
                res += pile // guess + (pile % guess > 0)
            return res <= h

        left = 0
        right = int(1e9)

        while left + 1 < right:
            mid = left + (right - left) // 2
            if chaewon(mid):
                right = mid
            else:
                left = mid
        
        return right
