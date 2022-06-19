def main():
    str = input()
    for i in range(int(len(str) / 2)):
        if str[i] != str[len(str) - 1 - i]:
            print('no')
            return
    print('yes')
    return


main()
