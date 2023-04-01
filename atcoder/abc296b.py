board = []
for i in range(8):
    board.append(list(input()))
for i in range(8):
    for j in range(8):
        if board[i][j] == "*":
            ax = chr(ord("a") + j)
            print(f"{ax}{8-i}")
