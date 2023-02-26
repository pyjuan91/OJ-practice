from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        left = 0
        right = len(height)-1
        ml = 0
        mr = 0
        res = 0
        while left <= right:
            if ml <= mr:
                res += max(0, ml-height[left])
                ml = max(ml, height[left])
                left += 1
            else:
                res += max(0, mr - height[right])
                mr = max(mr, height[right])
                right -= 1
        return res


s = Solution()
print(s.trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]))
