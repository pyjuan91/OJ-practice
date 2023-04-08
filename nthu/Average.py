def aver(*nums):  # fill in your declaration of parameters
    # your code here
    res = 0
    for num in nums:
        res += num
    return res / len(nums)


# Note that the following code is for local testing purposes only. You should leave this part of code unchanged and not submit it to the OJ system.
T = int(input())
for t in range(T):
    nums = [int(n) for n in input().split()]
    mean = aver(*nums)
    print(f"{mean}")
