H, W = map(int, input().split())
for i in range(H):
    li = list(map(int, input().split()))
    res = []
    for j in li:
        if j == 0:
            res.append(".")
        else:
            res.append(chr(ord("A") + j - 1))
    print("".join(res))
