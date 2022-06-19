mon, day = map(int, input().split())
s = (mon*2 + day) % 3
fortune = ('普通', '吉', '大吉')
print(fortune[s])