from typing import List


class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:

        def splitAndSort(a: List[int]) -> List[int]:
            if len(a) == 1:
                return a
            left = splitAndSort(a=a[:len(a)//2])
            right = splitAndSort(a=a[len(a)//2:])
            return merge(left, right)

        def merge(a: List[int], b: List[int]) -> List[int]:
            l = 0
            r = 0
            res = []
            while l < len(a) and r < len(b):
                if a[l] < b[r]:
                    res.append(a[l])
                    l += 1
                else:
                    res.append(b[r])
                    r += 1
            while l < len(a):
                res.append(a[l])
                l += 1
            while r < len(b):
                res.append(b[r])
                r += 1
            return res
        
        return splitAndSort(a=nums)

s = Solution()
print(s.sortArray([5,1,1,2,0,0]))