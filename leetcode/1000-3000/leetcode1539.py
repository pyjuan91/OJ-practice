from typing import List


class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        res = 1
        index = 0
        while k > 0 and index < len(arr):
            if res == arr[index]:
                index += 1
            else:
                k -= 1
            res += 1

        if k > 0:
            res += k

        return res - 1


s = Solution()
print(s.findKthPositive([2, 3, 4, 7, 11], 5))
