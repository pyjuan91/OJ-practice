from typing import List


class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        left = 0
        right = len(nums)-1
        if right == 1:
            return nums[0]
        while left+1 < right:
            mid = left + (right-left)//2
            if mid % 2 == 0:
                if mid+1 < len(nums) and nums[mid] == nums[mid+1]:
                    left = mid
                else:
                    right = mid
            else:
                if nums[mid] == nums[mid-1]:
                    left = mid + 1
                else:
                    right = mid - 1

        return nums[right]


s = Solution()
print(s.singleNonDuplicate([1, 1, 2, 3, 3, 4, 4, 8, 8]))
