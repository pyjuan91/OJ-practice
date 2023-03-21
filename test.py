inputList = []
while True:
    try:
        inputList.append(input())
    except EOFError as e:
        break

inputList.append('Sky')
inputList.append('Limit')
inputList.append('Fly')

print(f'{inputList[0]}{inputList[1]}{inputList[2]}{inputList[-3]}{inputList[-2]}{inputList[-1]}')

