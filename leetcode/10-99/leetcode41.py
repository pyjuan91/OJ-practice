from typing import List


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        ma = int(1e5) + 5
        li = [0 for i in range(ma)]
        for num in nums:
            if num < 1 or num > 1e5: continue
            li[num] = 1
        for i in range(1, ma):
            if li[i] == 0:
                return i

if __name__ == "__main__":
    s = Solution()
    print(s.firstMissingPositive([1,2,0]))