from typing import List


class Solution:
    def waysToReachTarget(self, target: int, types: List[List[int]]) -> int:
        mod = int(1e9 + 7)
        dp = [1] + [0] * target
        for count, marks in types:
            for i in range(target, 0, -1):
                for j in range(1, count + 1):
                    if i < marks * j:
                        break
                    dp[i] = (dp[i] + dp[i - marks * j]) % mod
        return dp[target]


s = Solution()
print(s.waysToReachTarget(target=6, types=[[6, 1], [3, 2], [2, 3]]))
