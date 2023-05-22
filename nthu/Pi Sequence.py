def Pi_seq(k):
    # your code here
    for i in range(k):
        yield (-1) ** i * 4 / ((i + 1) * 2 - 1)
    yield None


# Note that the following code is for local testing purposes only. You should leave this part of code unchanged and not submit it to the OJ system.
T = int(input())
for t in range(T):
    k = int(input())
    Pi_gen = Pi_seq(k)
    Pi = 0
    term = next(Pi_gen, None)
    while term != None:
        Pi += term
        term = next(Pi_gen, None)
    print(f"{Pi:.6f}")
