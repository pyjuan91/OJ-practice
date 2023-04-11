li = list(input().split(","))
cmd = rg = dr = ""
numbers = []
for e in li:
    try:
        numbers.append(int(e))
    except:
        if e[0] == "b" or e[0] == "f":
            dr = e[0]
            rg = int(e[1:])
        elif e[0] == "i":
            cmd = int(e[1:])
if cmd == "" or rg == 0:
    print("None")
    exit()


def all_same() -> bool:
    for i in range(1, len(numbers)):
        if numbers[i] != numbers[i - 1]:
            return False
    return True


if dr == "":
    if all_same():
        print(numbers[0])
    else:
        print("None")
    exit()

if dr == "f":
    if cmd == 1:
        print(max(numbers[: min(rg, len(numbers))]))
    else:
        print(min(numbers[: min(rg, len(numbers))]))
else:
    if cmd == 1:
        print(max(numbers[max(len(numbers) - rg, 0) :]))
    else:
        print(min(numbers[max(len(numbers) - rg, 0) :]))
