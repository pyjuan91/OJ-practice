from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []

        def chaewon(used: List[bool], cur: List[int]):
            if len(cur) == len(nums):
                res.append(cur.copy())
                return

            for i, b in enumerate(used):
                if b == False:
                    cur.append(nums[i])
                    used[i] = True
                    chaewon(used=used, cur=cur)
                    cur.pop()
                    used[i] = False
        
        used = [False for i in range(len(nums))]

        chaewon(used=used, cur=[])
        return res
    
s = Solution()
print(s.permute([1, 2, 3]))
