N = int(input())
li = list(map(int, input().split()))
first = True
for ele in li:
    if ele % 2 == 0:
        if first:
            first = False
        else:
            print(" ", end="")
        print(ele, end="")
