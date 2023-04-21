from typing import List


class Solution:
    def profitableSchemes(
        self, n: int, minProfit: int, group: List[int], profit: List[int]
    ) -> int:
        mod = 10**9 + 7
        dp = [[0] * 105 for _ in range(100005)]
        dp[0][0] = 1

        for i in range(len(group)):
            required_people = group[i]
            profit_maken = profit[i]

            for money in range(minProfit, -1, -1):
                for person in range(n - required_people, -1, -1):
                    dp[min(minProfit, money + profit_maken)][
                        person + required_people
                    ] += dp[money][person]
                    dp[min(minProfit, money + profit_maken)][
                        person + required_people
                    ] %= mod

        return sum(dp[minProfit]) % mod
