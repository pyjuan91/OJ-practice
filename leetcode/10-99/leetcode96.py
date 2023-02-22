class Solution:
    def numTrees(self, n: int) -> int:
        dp = [0 for i in range(20)]
        dp[0], dp[1], dp[2] = 1, 1, 2

        def chaewon(cur: int):
            if dp[cur] != 0:
                return dp[cur]

            res = 0
            for i in range(1, cur+1):
                res += chaewon(i-1) * chaewon(cur-i)

            dp[cur] = res
            return res
        return chaewon(n)


s = Solution()
print(s.numTrees(1))
