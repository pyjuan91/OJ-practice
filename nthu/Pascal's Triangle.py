def pascal(row, col):
    # your code here
    if col == 0 or row == col:
        return 1
    return pascal(row=row - 1, col=col - 1) + pascal(row=row - 1, col=col)


def print_pascal(n):
    # your code here
    for row in range(n):
        for col in range(row + 1):
            print(f"{pascal(row=row, col=col):3d}", end="")
        print()


# Note that the following code is for local testing purposes only. You should leave this part of code unchanged and not submit it to the OJ system.
T = int(input())
for t in range(T):
    n = int(input())
    print_pascal(n)
