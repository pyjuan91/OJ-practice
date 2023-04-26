class OrderedStream:
    def __init__(self, n: int):
        self.chunk = 1
        self.n = n
        self.li = [None] * (n + 1)

    def insert(self, idKey: int, value: str):
        self.li[idKey] = value
        if not self.li[self.chunk]:
            return []
        res = []
        for i in range(self.chunk, self.n + 1):
            if not self.li[i]:
                self.chunk = i
                break
            res.append(self.li[i])
            self.chunk = i + 1
        return res


# Note that the following code is for local testing purposes only. You should leave this part of code unchanged and not submit it to the OJ system.
stream = OrderedStream(5)
print(stream.insert(3, "ccccc"))
print(stream.insert(1, "aaaaa"))
print(stream.insert(2, "bbbbb"))
print(stream.insert(5, "eeeee"))
print(stream.insert(4, "ddddd"))
