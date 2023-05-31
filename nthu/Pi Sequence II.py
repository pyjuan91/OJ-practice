from fractions import Fraction


def Pi_seq(n):
    for i in range(n):
        yield Fraction(numerator=(((-1) ** i) * 4), denominator=(2 * i + 1))


# Note that the following code is for local testing purposes only. You should leave this part of code unchanged and not submit it to the OJ system.
T = int(input())
for t in range(T):
    k = int(input())
    Pi = Fraction()
    for t in Pi_seq(k):
        Pi += t
    print(f"{Pi}")
