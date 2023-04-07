n, k = map(int, input().split())
dislike = list(map(int, input().split()))


def chaewon(a: int) -> bool:
    while a > 0:
        if a % 10 in dislike:
            return False
        a //= 10
    return True
for i in range(n, int(1e7)):
    if chaewon(i):
        print(i)
        exit()