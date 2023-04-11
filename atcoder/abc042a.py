a, b, c = map(int, input().split())
from collections import defaultdict

dic = defaultdict(int)
dic[a] += 1
dic[b] += 1
dic[c] += 1
if dic[5] == 2 and dic[7] == 1:
    print("YES")
else:
    print("NO")
