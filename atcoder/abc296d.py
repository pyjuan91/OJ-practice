import math

N, M = map(int, input().split())
if M > N * N:
    print(-1)
    exit()
if M <= N:
    print(M)
    exit()
res = 1e18
for i in range(1, N + 1):
    j = (M + i - 1) // i
    if j <= N:
        res = min(res, i * j)
    if i > j:
        break

print(res)
