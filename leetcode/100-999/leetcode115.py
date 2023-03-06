class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        dp = [[0] * (len(s) + 1) for i in range(len(t) + 1)]
        for i in range(len(s)):
            dp[0][i] = 1

        for i in range(len(t)):
            for j in range(len(s)):
                if t[i] == s[j]:
                    dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j]
                else:
                    dp[i + 1][j + 1] = dp[i + 1][j]

        return dp[len(t)][len(s)]


s = Solution()
print(s.numDistinct(s = "babgbag", t = "bag"))
