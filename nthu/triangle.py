from math import sqrt # you may use this function to calculate the area

class Triangle:
    # accepts the three sides of triangle
    def __init__(self, s0, s1, s2):
        # your code here
        self.s0 = s0
        self.s1 = s1
        self.s2 = s2

    # return the perimeter of this triangle.
    @property
    def perimeter(self):
        # your code here
        return self.s0 + self.s1 + self.s2

    # return the area of this triangle.
    @property
    def area(self):
        # your code here
        s = self.perimeter / 2
        return sqrt(s * (s-self.s0) * (s-self.s1) * (s-self.s2))


# Note that the following code is for local testing purposes only. You should leave this part of code unchanged and not submit it to the OJ system.
T = int(input())
for t in range(T):
    side = list(map(int, input().split()))
    t = Triangle(side[0], side[1], side[2])
    print(f'{t.perimeter} {t.area:.2f}')
