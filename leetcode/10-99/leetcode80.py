from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        slot = 2
        for i in range(2, len(nums)):
            if nums[i] != nums[slot - 2]:
                nums[slot] = nums[i]
                slot += 1
        return min(len(nums), slot)


s = Solution()
s.removeDuplicates(nums=[1, 1, 1, 2, 2, 3])
