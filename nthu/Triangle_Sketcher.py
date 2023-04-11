def trisketch(n):
    # your code here
    for i in range(n):
        print(f"{'*' * (i+1)}")


# Note that the following code is for local testing purposes only. You should leave this part of code unchanged and not submit it to the OJ system.
T = int(input())
for t in range(T):
    n = int(input())
    trisketch(n)
