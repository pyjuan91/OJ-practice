from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        one_start = one_end = 0
        for i, v in enumerate(nums):
            if v == 1:
                nums[one_end], nums[i] = nums[i], nums[one_end]
                one_end += 1
            elif v == 0:
                print(nums[one_start], nums[one_end], nums[i])
                if one_end == i:
                    nums[one_start], nums[i] = nums[i], nums[one_start]
                else:
                    nums[one_end], nums[i], nums[one_start] = (
                        nums[one_start],
                        nums[one_end],
                        nums[i],
                    )
                one_start += 1
                one_end += 1


s = Solution()
nums = [0, 1]
s.sortColors(nums=nums)
print(nums)
