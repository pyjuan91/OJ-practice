N, K, X, Y = int(input()), int(input()), int(input()), int(input())
print(min(N, K) * X + max(0, N - K) * Y)
