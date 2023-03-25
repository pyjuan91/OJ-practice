H, W = map(int, input().split())
g = []
for _ in range(H):
    g.append(input())
dp = [[int(1e5) for _ in range(W)] for _ in range(H)]
dp[0][0] = 0 if g[0][0] == "." else 1
for i in range(H):
    for j in range(W):
        if i > 0:
            dp[i][j] = min(
                dp[i][j],
                dp[i - 1][j] + (1 if g[i - 1][j] == "." and g[i][j] == "#" else 0),
            )
        if j > 0:
            dp[i][j] = min(
                dp[i][j],
                dp[i][j - 1] + (1 if g[i][j - 1] == "." and g[i][j] == "#" else 0),
            )
print(dp[H - 1][W - 1])
