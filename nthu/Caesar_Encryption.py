import string

t = int(input())
for kase in range(1, t + 1):
    s = list(input())
    for i, c in enumerate(s):
        if c in string.ascii_lowercase:
            s[i] = chr(((ord(c) - ord("a") + 1) % 26) + ord("a"))
        elif c in string.ascii_uppercase:
            s[i] = chr(((ord(c) - ord("A") + 1) % 26) + ord("A"))
    s = "".join(s)
    print(f"Case #{kase}: {s}")
