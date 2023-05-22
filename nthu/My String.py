class MyString(str):
    def __lshift__(self, val):
        n = len(self)
        if n == 0:
            return ""
        val = val % n
        return self[val:] + self[:val]

    def __rshift__(self, val):
        n = len(self)
        if n == 0:
            return ""
        val = val % n
        val = n - val
        return self.__lshift__(val=val)


# Note that the following code is for local testing purposes only. You should leave this part of code unchanged and not submit it to the OJ system.
T = int(input())
for i in range(1, T + 1):
    s = MyString(input())
    n1, n2 = map(int, input().split())
    print(f'Case #{i}_1: After left rotate {n1} positions the string will be "{s<<n1}"')
    print(
        f'Case #{i}_2: After right rotate {n2} positions the string will be "{s>>n2}"'
    )
    print(f'Case #{i}_3: The origin string: "{s}"')
