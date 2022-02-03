import math
a, b, c = map(int, input().split())
if b*b - 4*a*c >= 0:
    x1 = int((-b + math.sqrt(b * b - 4 * a * c)) / (2 * a))
    x2 = int((-b - math.sqrt(b * b - 4 * a * c)) / (2 * a))
    if x1 == x2:
        print('Two same roots x=' + str(x1))
    else:
        print('Two different roots x1=' + str(x1) + ' , x2='  + str(x2))
else:
    print('No real root')