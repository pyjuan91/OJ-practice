T = int(input())
for i in range(1, T + 1):
    a = int(input())
    if a >= 128:
        a = (a * 2) % 256 + 1
    else:
        a = a << 1
    print(f"Case #{i}: {a}")
