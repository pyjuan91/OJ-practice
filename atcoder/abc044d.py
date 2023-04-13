import math

N, S = int(input()), int(input())


def chaewon(b, n):
    if n < b:
        return n
    return (n % b) + chaewon(b, n // b)


def find_factor(a):
    small = []
    big = []
    for i in range(1, math.ceil(math.sqrt(a)) + 1):
        if a % i == 0:
            small.append(i)
            big.append(a // i)
    return small + big[::-1]


if S > N:
    print(-1)
elif S == N:
    print(N + 1)
else:
    # x1 = (n-s) / (b-1)
    li = find_factor(N - S)
    for b in li:
        if chaewon(b + 1, N) == S:
            print(b + 1)
            exit()

    print(-1)
