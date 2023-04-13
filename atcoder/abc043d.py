s = input()
for i in range(len(s)):
    if i + 1 < len(s) and s[i] == s[i + 1]:
        print(f"{i+1} {i+2}")
        exit()
    if i + 2 < len(s) and s[i] == s[i + 2]:
        print(f"{i+1} {i+3}")
        exit()
print("-1 -1")
