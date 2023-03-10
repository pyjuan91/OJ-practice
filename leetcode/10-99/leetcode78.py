from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []

        def chaewon(cl: List[int], cp: int):
            if cp == len(nums):
                res.append(cl.copy())
                return
            chaewon(cl=cl, cp=cp+1)
            cl.append(nums[cp])
            chaewon(cl=cl, cp=cp+1)
            cl.pop()

        chaewon(cl=[], cp=0)
        return res

s = Solution()
print(s.subsets([1,2,3]))