from collections import defaultdict, Counter

lines = []
while True:
    try:
        lines.append(list(input().split()))
    except:
        break

counter = Counter()
for line in lines:
    for word in line:
        for char in word:
            counter[char] += 1

rep = ord("a")
dic = defaultdict()
for freq in counter.most_common():
    dic[freq[0]] = chr(rep)
    rep += 1

dic[" "] = " "
for line in lines:
    rep = []
    for word in line:
        nw = ""
        for c in word:
            nw += dic[c]
        rep.append(nw)
    print(" ".join(rep))
