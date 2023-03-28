T = int(input())
for kase in range(1, T + 1):
    C = list(map(int, input().split()))
    setc = set(C)
    print(f"Case #{kase}: {min(len(C)//2, len(setc))}")

