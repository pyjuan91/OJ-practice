N, K = map(int, input().split())
A = list(map(int, input().split()))
res = 0
MOD = int(1e9 + 7)
for i in range(N):
    for j in range(i + 1, N):
        if A[i] < A[j]:
            res = (res + K * (K - 1) // 2) % MOD
        elif A[i] > A[j]:
            res = (res + K * (K + 1) // 2) % MOD
print(res)
