n, a, b = map(int, input().split())

li = list(map(int, input().split()))

for i in range(n):
    if li[i] == a + b:
        print(i + 1)
        exit()
