N, A = map(int, input().split())
X = list(map(int, input().split()))
from collections import defaultdict

# dp[i][j][k] == select j items in total i things, sum is k's number
dp = [[defaultdict(int) for _ in range(N + 2)] for _ in range(N + 2)]
dp[0][0][0] = 1

for i in range(1, N + 1):
    for j in range(0, i + 1):
        for k in range(50 * i + 1):
            if dp[i - 1][j][k]:
                dp[i][j][k] += dp[i - 1][j][k]
                dp[i][j + 1][k + X[i - 1]] += dp[i - 1][j][k]

res = 0
for i in range(1, N + 1):
    res += dp[N][i][A * i]

print(res)
