def evaluate(expr):
    # your code here
    return eval(expr)
# Note that the following code is for local testing purposes only. You should leave this part of code unchanged and not submit it to the OJ system.
T = int(input())
for t in range(T):
    result = evaluate(input())
    print(result)
