n, m = map(int, input().split())
route = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split())
    route[a].append(b)
    route[b].append(a)
vist = [True] + [False] * n
ans = [0] * (n + 1)
q = [1]
vist[1] = True
while q:
    cur = q.pop(0)
    for child in route[cur]:
        if not vist[child]:
            vist[child] = True
            ans[child] = cur
            q.append(child)
if not all(vist):
    print('No')
else:
    print('Yes')
    for i in range(2, n+1):
        print(ans[i])