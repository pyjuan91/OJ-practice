h, w, a, b = map(int, input().split())
MOD = 10**9 + 7


def fast_power(a, b) -> int:
    res = 1
    while b > 0:
        if b & 1:
            res *= a
            res %= MOD
        b >>= 1
        a *= a
        a %= MOD
    return res


n = h + w + 1
factorial = [1] * (n)
for i in range(1, n):
    factorial[i] = i * factorial[i - 1] % MOD

inverse_factorial = [fast_power(f, MOD - 2) for f in factorial]


def C(a: int, b: int) -> int:
    return (factorial[a] * inverse_factorial[a - b] % MOD) * inverse_factorial[b] % MOD


def chaewon(a: int, b: int) -> int:
    return C(a + b - 2, a - 1)


res = 0
for i in range(b + 1, w + 1):
    res += chaewon(h - a, i) * chaewon(a, w + 1 - i)
    res %= MOD
print(res)
