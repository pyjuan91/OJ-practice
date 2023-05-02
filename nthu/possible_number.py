T = int(input())


def chaewon(n: int, k: int) -> list:
    if n == 1:
        if k == 0:
            return ["0"]
        return ["1"]

    if k == 0:
        return ["0" * n]
    if n == k:
        return ["1" * n]
    # head zero
    head_zero = chaewon(n - 1, k)
    for i, s in enumerate(head_zero):
        head_zero[i] = "0" + s
    # head one
    head_one = chaewon(n - 1, k - 1)
    for i, s in enumerate(head_one):
        head_one[i] = "1" + s

    return head_zero + head_one


def binary_to_decimal(s: str):
    res = 0
    for c in s:
        res *= 2
        if c == "1":
            res += 1
    return res


for i in range(T):
    n, k = map(int, input().split())
    res = chaewon(n=n, k=k)
    # print(res)
    ans = []
    for s in res:
        ans.append(binary_to_decimal(s))
    print(f"Case #{i+1}: {ans}")
