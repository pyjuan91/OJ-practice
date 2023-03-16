from itertools import accumulate
import operator
from typing import List

from collections import Counter, defaultdict


class Solution:
    def beautifulSubarrays(self, nums: List[int]) -> int:
        prefix_xor = defaultdict(int)
        prefix_xor[0] = 1
        prefix_xor_sum = 0
        res = 0
        for num in nums:
            prefix_xor_sum ^= num
            res += prefix_xor[prefix_xor_sum]
            prefix_xor[prefix_xor_sum] += 1

        return res


s = Solution()
print(s.beautifulSubarrays(nums=[1,10,4]))

