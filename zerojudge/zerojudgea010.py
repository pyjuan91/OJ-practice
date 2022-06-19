import math
primeList = []
isPrime = []
maxn = 2000000


def catchPrime():
    # init
    for i in range(maxn):
        isPrime.append(True)
    isPrime[0] = False
    isPrime[1] = False
    # faster
    sqrtMaxn = int(math.sqrt(maxn))
    # simple prime algorithm
    for i in range(2, sqrtMaxn):
        if isPrime[i]:
            for k in range(int((maxn-1)/i), i-1, -1):
                if isPrime[k]:
                    isPrime[i * k] = False
    # put into a list
    for i in range(maxn):
        if isPrime[i]:
            primeList.append(i)


catchPrime()
num = int(input())
cnt = 0
fac = primeList[cnt]
first = True
while num > 1 and fac <= num:
    d = 0
    while num > 1 and num % fac == 0:
        d += 1
        num = int(num / fac)
    if not(first):
        print(' * ', end='')
    if d > 0:
        first = False
        print(fac, end='')
        if d > 1:
            print('^' + str(d), end='')
    if num > 1 and fac <= num:
        cnt += 1
        while num % primeList[cnt] != 0:
            cnt += 1
        fac = primeList[cnt]

print()
