from typing import List


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        if len(nums) == 1:
            return [[nums[0]], []]
        child = self.subsetsWithDup(nums=nums[1:])
        if nums[0] != nums[1]:
            for c in child:
                res.append([nums[0]] + c)
            res.extend(child)
        else:
            for c in child:
                res.append([nums[0]] + c)
            child = [c for c in child if not c or c[0] != nums[0]]
            res.extend(child)
        return res


s = Solution()
print(s.subsetsWithDup(nums=[1, 2, 2, 2]))
