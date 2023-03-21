from typing import List


class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        index = res = 0
        while index < len(nums):
            if nums[index] != 0:
                index += 1
            else:
                before = index
                while index < len(nums) and nums[index] == 0:
                    index += 1
                before = index - before
                res += (before * (before + 1)) // 2
        return res
