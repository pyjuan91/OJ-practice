from typing import List


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        buff = int(1e4)
        counter = [0] + [0] * 2 * buff
        for num in nums:
            counter[num+buff] += 1
        index = 2 * buff
        while k > 0:
            while counter[index] == 0:
                index -= 1
            k -= counter[index]
            counter[index] = 0
        return index - buff

s = Solution()
print(s.findKthLargest(nums = [3,2,1,5,6,4], k = 2))
