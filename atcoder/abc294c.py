N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
a, b, cnt = [], [], 1
while A and B:
    if A[0] < B[0]:
        a.append(cnt)
        A.pop(0)
    else:
        b.append(cnt)
        B.pop(0)
    cnt += 1
while A:
    a.append(cnt)
    A.pop(0)
    cnt += 1
while B:
    b.append(cnt)
    B.pop(0)
    cnt += 1

print(*a)
print(*b)