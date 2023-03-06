from collections import Counter
from typing import List


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        cnt = Counter(nums)
        print(cnt)

        def chaewon(cur: List[int]):
            if len(cur) == len(nums):
                res.append(cur)
                return
            for key in cnt:
                if cnt[key] > 0:
                    cnt[key] -= 1
                    chaewon(cur + [key])
                    cnt[key] += 1

        chaewon([])

        return res


s = Solution()
print(s.permuteUnique([3, 1, 2]))
