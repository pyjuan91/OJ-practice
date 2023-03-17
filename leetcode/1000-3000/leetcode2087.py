from typing import List


class Solution:
    def maxScore(self, nums: List[int]) -> int:
        nums.sort()
        nums.reverse()
        res = prefix_sum = 0
        for num in nums:
            prefix_sum += num
            if prefix_sum <= 0:
                break
            res += 1
        return res


s = Solution()
print(s.maxScore(nums=[-2, -3, 0]))
