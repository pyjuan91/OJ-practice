from typing import List
import bisect

class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        res = []
        m = len(potions)
        for spell in spells:
            tar = success // spell + int(success % spell > 0)
            lower_bound = bisect.bisect_left(a=potions, x=tar, lo=0, hi=m)
            res.append(m - lower_bound)
        return res
    
s = Solution()
print(s.successfulPairs(spells = [5,1,3], potions = [1,2,3,4,5], success = 7))
            