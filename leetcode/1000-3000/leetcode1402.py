from typing import List


class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        satisfaction.sort(reverse=True)
        pre = res = 0
        for satis in satisfaction:
            pre += satis
            if pre < 0:
                break
            res += pre
        return res