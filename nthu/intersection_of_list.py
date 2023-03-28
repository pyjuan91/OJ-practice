T = int(input())
for kase in range(1, T + 1):
    lia = list(map(int, input().split()))
    lib = list(map(int, input().split()))
    seta, setb = set(lia), set(lib)
    seta.intersection_update(setb)
    seta = list(seta)
    seta.sort()
    print(f"Case #{kase}: {seta}")
