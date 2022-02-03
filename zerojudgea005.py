def check_arithmetic(seq):
    diff = seq[1] - seq[0]
    for i in range(3):
        if seq[i + 1] - seq[i] != diff:
            return
    seq.append(seq[3] + diff)
    return

def check_geometric(seq):
    ratio = seq[1] / seq[0]
    for i in range(3):
        if seq[i + 1] / seq[i] != ratio:
            return
    seq.append(int(seq[3] * ratio))
    return

kase = int(input())
for f in range(kase):
    seq = list(map(int, input().split()))
    check_arithmetic(seq)
    check_geometric(seq)
    for i in range(4):
        print(seq[i], end = ' ')
    print(seq[4])

