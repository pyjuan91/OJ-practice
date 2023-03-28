N = int(input())
X = list(map(int, input().split()))
res = int(1e18)
for p in range(101):
    score = 0
    for x in X:
        score += (p-x) ** 2
    res = min(res, score)
print(res)