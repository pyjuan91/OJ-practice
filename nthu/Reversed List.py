from copy import deepcopy
def reverse(L: list):
    # your code here
    if not L:
        return []
    chaechae = True
    for l in L:
        if type(l) == list:
            chaechae = False
            break

    if chaechae:
        return L[::-1]

    res = []
    for i in range(len(L)):
        if type(L[i]) == list:
            res.append(reverse(deepcopy(L[i])))
        else:
            res.append(L[i])
    
    return res[::-1]


# Note that the following code is for local testing purposes only. You should leave this part of code unchanged and not submit it to the OJ system.
T = int(input())
for t in range(T):
    L = eval(input())
    # L = input()
    rL = reverse(L)
    # print(L)
    print(rL)
