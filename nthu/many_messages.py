import sys
a, b, c = int(input()), int(input()), int(input())
for i in range(1, 4):
    if a + i * b >= c:
        print(a + i * b)
        sys.exit()

print("Who knows...")
