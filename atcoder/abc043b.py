seq = input()
res = []
for c in seq:
    if c == 'B':
        if res:
            res.pop()
    else:
        res.append(c)
print("".join(res))