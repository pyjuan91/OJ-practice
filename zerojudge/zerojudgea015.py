while True:
    try:
        n, m = map(int, input().split())
        matrix = []
        for i in range(n):
            row = list(map(int, input().split()))
            matrix.append(row)
        for j in range(m):
            for i in range(n):
                print(matrix[i][j], end = ' ')
            print()
    except EOFError:
        break