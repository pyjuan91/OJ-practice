class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        # dp[i][j] = from i to j's longest palindrome
        n = len(s)
        dp = [[0] * (n + 1) for _ in range(n + 1)]

        def chaewon(i: int, j: int) -> int:
            if i > j:
                return 0
            if i == j:
                return 1
            if dp[i][j]:
                return dp[i][j]
            if s[i] == s[j]:
                dp[i][j] = 2 + chaewon(i + 1, j - 1)
            else:
                dp[i][j] = max(chaewon(i + 1, j), chaewon(i, j - 1))

            return dp[i][j]

        return chaewon(0, n - 1)
