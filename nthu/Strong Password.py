from re import search


def is_strong(passwd):
    if len(passwd) < 8:
        return False
    if not search("[a-z]", passwd):
        return False
    if not  search("[A-Z]", passwd):
        return False
    if not search("[0-9]", passwd):
        return False
    if not search("[-!@#$%^&*()+]", passwd):
        return False
    for i, c in enumerate(passwd):
        if i + 1 < len(passwd) and c == passwd[i + 1]:
            return False
    return True


# Note that the following code is for local testing purposes only. You should leave this part of code unchanged and not submit it to the OJ system.
T = int(input())
for t in range(T):
    passwd = input()
    if is_strong(passwd):
        print("Strong")
    else:
        print("Weak")
