try:
    while True:
        y = int(input())
        if y % 400 == 0 or (y % 4 == 0 and y % 100 != 0):
            print('閏年')
        else:
            print('平年')
except EOFError:
    pass