from typing import List


class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        bound = nearestMinK = nearestMaxK = -1
        res = 0

        for index, num in enumerate(nums):
            if num < minK or num > maxK:
                bound = index

            if num == minK:
                nearestMinK = index
            if num == maxK:
                nearestMaxK = index

            head = min(nearestMinK, nearestMaxK)
            if head > bound:
                res += head - bound
        
        return res
