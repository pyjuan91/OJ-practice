from collections import defaultdict

dic = defaultdict(int)
title = []
while True:
    try:
        name, io, amount = input().split()
        name = name.lower()
        if not name in title:
            title.append(name)
        if io == "I":
            dic[name] += int(amount)
        else:
            dic[name] -= int(amount)
    except:
        break

for t in title:
    if dic[t]:
        print(t, dic[t])
