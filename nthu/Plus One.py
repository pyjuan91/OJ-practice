t = int(input())
for kase in range(1, t + 1):
    num = list(map(int, input().split()))
    num.reverse()
    num[0] += 1
    for i, v in enumerate(num):
        if v > 9:
            num[i] = 0
            if i + 1 < len(num):
                num[i + 1] += 1
            else:
                num.append(1)
    num.reverse()
    print(f'Case #{kase}: {num}')
