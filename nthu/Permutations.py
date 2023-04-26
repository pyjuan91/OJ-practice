def permute(nums):
    # your code here
    if len(nums) == 1:
        return [nums]
    res = []
    for i in range(len(nums)):
        if i == 0:
            child = nums[1:]
        elif i == len(nums)-1:
            child = nums[:-1]
        else:
            child = nums[:i] + nums[i+1:]
        children = permute(child)
        for child in children:
            res.append([nums[i]] + child)
    
    return res

# Note that the following code is for local testing purposes only. You should leave this part of code unchanged and not submit it to the OJ system.
T = int(input())
for t in range(T):
    nums = list(map(int, input().split()))
    print(permute(nums))
