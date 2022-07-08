from math import sqrt

while True:
    try:
        times = int(input())
        for i in range(times):
            a, b, c = list(map(int, input().split()))
            if b**2-4*a*c >= 0 and a != 0:
                if sqrt(b**2-4*a*c) == 0 or sqrt(b**2-4*a*c) % 1 == 0:
                    print("Yes")
                else:
                    print("No")
            else:
                print("No")
    except:
        break
