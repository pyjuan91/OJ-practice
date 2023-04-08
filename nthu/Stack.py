stack = []
sum = 0


def init():
    global sum, stack
    stack.clear()
    sum = 0


def push(val: int):
    global sum, stack
    stack.append(val)
    sum += val**2


def pop():
    global sum, stack
    sum -= stack.pop() ** 2


def top() -> int:
    return stack[-1]


def getSquareSum():
    return sum
