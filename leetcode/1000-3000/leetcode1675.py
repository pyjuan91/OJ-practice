from typing import List
import heapq
import numpy as np


class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        pq = []
        nums = np.unique(np.array(nums))
        ma = -float('inf')
        mi = float('inf')
        for num in nums:
            if num % 2 == 1:
                num *= 2
            heapq.heappush(pq, -num)
            ma = max(ma, num)
            mi = min(mi, num)

        res = ma-mi
        while pq[0] % 2 == 0:
            front = -pq[0]
            ma = front
            res = min(res, ma-mi)
            mi = min(mi, front//2)
            heapq.heappushpop(pq, -(front//2))

        return min(res, -pq[0]-mi)


s = Solution()
print(s.minimumDeviation([4, 9, 4, 5]))
