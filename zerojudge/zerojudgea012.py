dic = {'I': 1, 'V': 5, 'X': 10, 'L': 50,
       'C': 100, 'D': 500, 'M': 1000}


def getNumber(str):
    num = 0
    i = 0
    while i < len(str):
        if i != len(str) - 1 and dic[str[i]] < dic[str[i + 1]]:
            num += dic[str[i + 1]] - dic[str[i]]
            i += 1
        else:
            num += dic[str[i]]
        i += 1
    return num


def getString(ans):
    if ans == 0:
        return 'ZERO'
    str = ''
    while ans >= 1000:
        str += 'M'
        ans -= 1000
    while ans >= 900:
        str += 'CM'
        ans -= 900
    while ans >= 500:
        str += 'D'
        ans -= 500
    while ans >= 400:
        str += 'CD'
        ans -= 400
    while ans >= 100:
        str += 'C'
        ans -= 100
    while ans >= 90:
        str += 'XC'
        ans -= 90
    while ans >= 50:
        str += 'L'
        ans -= 50
    while ans >= 40:
        str += 'XL'
        ans -= 40
    while ans >= 10:
        str += 'X'
        ans -= 10
    while ans >= 9:
        str += 'IX'
        ans -= 9
    while ans >= 5:
        str += 'V'
        ans -= 5
    while ans >= 4:
        str += 'IV'
        ans -= 4
    while ans >= 1:
        str += 'I'
        ans -= 1
    return str


while True:
    str = input()
    if str == '#':
        break
    str1, str2 = str.split()
    num1 = getNumber(str1)
    num2 = getNumber(str2)
    ans = abs(num1 - num2)
    print(getString(ans))
