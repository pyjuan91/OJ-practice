from collections import Counter, defaultdict

s, code = input(), input()
counter = Counter()
dic = defaultdict()
for char in s:
    char = char.lower()
    counter[char] += 1

encode = "1"
for cnt in counter.most_common()[: len(counter) - 1]:
    dic[encode] = cnt[0]
    encode = "0" + encode

dic[(len(encode) - 1) * "0"] = counter.most_common()[len(counter) - 1][0]
index = 0
res = []
while index < len(code):
    right = index
    while (
        right < len(code)
        and right - index + 1 < (len(encode) - 1)
        and code[right] != "1"
    ):
        right += 1
    if right < len(code):
        res.append(dic[code[index : right + 1]])
    else:
        res.append(dic[code[index : len(code)]])
    index = right + 1
print("".join(res))
