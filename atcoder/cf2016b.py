n, a, b = map(int, input().split())
s = input()
all_rank = a + b
oversea_rank = b
for c in s:
    if c == "a":
        if all_rank:
            all_rank -= 1
            print("Yes")
        else:
            print("No")
    elif c == "b":
        if all_rank and oversea_rank:
            all_rank -= 1
            oversea_rank -= 1
            print("Yes")
        else:
            print("No")
    else:
        print("No")
