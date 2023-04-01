n = int(input())
seq = list(input())
for i in range(n - 1):
    if seq[i] == seq[i + 1]:
        print("No")
        exit()

print("Yes")
