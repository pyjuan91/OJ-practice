class RecentCounter:

    def __init__(self):
        self.left = 0
        self.req = []
    def ping(self, t):
        self.req.append(t)
        while self.left < len(self.req) and self.req[self.left] < t-3000:
            self.left += 1
        return len(self.req) - self.left

# Note that the following code is for local testing purposes only. You should leave this part of code unchanged and not submit it to the OJ system.
T = int(input())
for t in range(1,T+1):
    counter = RecentCounter()
    calls = list(map(int,input().split()))
    for ind,time in enumerate(calls):
        print(f'Case #{t}_{ind}: {counter.ping(time)}')