testcase = int(input())
for i in range(1, testcase + 1):
    s, t = input().split(" ")
    print(f"Case #{i}: {s.find(t)}")
