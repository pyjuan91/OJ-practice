str = input()
list = [ord(c) for c in str]
for i in range(len(list)):
    list[i] += int(ord('*') - ord('1'))
nl = [chr(i) for i in list]
for i in nl:
    print(i, end = '')