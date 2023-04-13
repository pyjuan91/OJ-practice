s = input()
res = 0
for c in s:
    res ^= 1 << ord(c)
if res:
    print("No")
else:
    print("Yes")
