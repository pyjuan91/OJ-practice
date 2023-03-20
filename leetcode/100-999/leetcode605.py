from typing import List


class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        last = -1
        res = 0
        for i, v in enumerate(flowerbed):
            if v == 1:
                res += (i - last - 1) // 2
                last = i + 1
        res += (len(flowerbed) - last) // 2
        return n <= res


s = Solution()
print(s.canPlaceFlowers([1, 0, 0, 0, 0], 2))
