from typing import List


class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        left = 0
        right = sum(weights)

        def check(mid):
            cs = 0
            cd = 0
            for item in weights:
                if item > mid:
                    return False
                if cs+item <= mid:
                    cs += item
                else:
                    cd += 1
                    cs = item
            return cd + 1 <= days

        while left+1 < right:
            mid = left + (right-left)//2
            if check(mid=mid):
                right = mid
            else:
                left = mid

        return right

s = Solution()
print(s.shipWithinDays([1,2,3,1,1], 4))
