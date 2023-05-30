from statistics import mean


def average(scores):
    return list(map(mean, zip(*scores)))


# Note that the following code is for local testing purposes only. You should leave this part of code unchanged and not submit it to the OJ system.
T = int(input())
for t in range(T):
    k = int(input())
    scores = [map(int, input().split()) for _ in range(k)]
    avers = average(scores)
    # for m in avers:
    #     print(f'{m:.2f}', end=' ')
    # print()
