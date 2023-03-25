N, M = map(int, input().split())
X = list(map(int, input().split()))
if N >= M:
    print(0)
    exit()
X.sort()
sec = []
for i, v in enumerate(X):
    if i > 0:
        sec.append(X[i] - X[i-1])
sec.sort()
for _ in range(N-1):
    sec.pop()
print(sum(sec))