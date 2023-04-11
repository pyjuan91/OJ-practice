friction = list(map(float, input().split()))
n = len(friction)


class User:
    def __init__(self, id, sc, cheat) -> None:
        self.id = id
        self.sc = sc
        self.cheat = cheat
        self.res = 0

    def calculate(self) -> None:
        for i in range(n):
            if i + 1 not in self.cheat:
                self.res += 100 * friction[i] * self.sc[i]
        self.res /= sum(friction)


users = []
block = []
while True:
    try:
        user = list(input().split(","))
    except EOFError:
        break
    try:
        int(user[0])
        id = user[1]
        sc = []
        for i in range(2, 2 + n):
            sc.append(eval(user[i]))
        cheat = []
        for i in range(2 + n + 1, len(user)):
            cheat.append(int(user[i][1:]))
        users.append(User(id=id, sc=sc.copy(), cheat=cheat.copy()))
    except:
        block.append(user[0][1:])   


def match(id1, id2) -> bool:
    if len(id1) < len(id2):
        return False
    i = len(id2) - 1
    j = len(id1) - 1
    while i >= 0:
        if id1[j] != id2[i]:
            return False
        i -= 1
        j -= 1
    return True


def chaewon(id1) -> bool:
    for b in block:
        if match(id1, b):
            return True
    return False


for user in users:
    user.calculate()
    if chaewon(user.id):
        print(f"{user.id},0.00")
    else:
        print(f"{user.id},{user.res:.2f}")
