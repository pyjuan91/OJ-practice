def adder(*args) -> int:
    res = 0
    add = -1
    for a in args:
        add *= -1
        res += a * add
    return res


if __name__ == "__main__":
    t = int(input())
    for i in range(1, t + 1):
        args = map(int, input().split())
        print("Case #%d: %d" % (i, adder(*args)))
