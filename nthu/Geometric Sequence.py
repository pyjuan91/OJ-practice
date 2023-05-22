def Geometric_Sequence(first,common_ratio):
    #Your code here
    while True:
        yield first % 100
        first = first * common_ratio % 100

# Note that the following code is for local testing purposes only. You should leave this part of code unchanged and not submit it to the OJ system.
T = int(input())
for i in range(1,T+1):
    n,f,cr = list(map(int,input().split()))
    g = Geometric_Sequence(f,cr)
    for j in range(n):
        print(f"Case #{i}_{j}: {next(g)}")
