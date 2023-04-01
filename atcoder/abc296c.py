N, X = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
if X < 0:
    A.reverse()
s = set()
for a in A:
    s.add(a)
    if a - X in s:
        print("Yes")
        exit()
print("No")