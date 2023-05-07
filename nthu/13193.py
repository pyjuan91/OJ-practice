from functools import cmp_to_key


def custom_compare(s1: str, s2: str):
    if len(s1) == len(s2):
        s1os, s2os = sum(map(ord, s1)), sum(map(ord, s2))
        if s1os == s2os:
            return 0
        elif s1os > s2os:
            return -1
        else:
            return 1
    elif len(s1) > len(s2):
        return -1
    else:
        return 1


n = int(input())

li = []
while True:
    try:
        line = list(input().split())
        li.extend(line)
    except:
        break

li.sort(key=cmp_to_key(custom_compare))

for i in range(min(len(li), n)):
    print(li[i])
