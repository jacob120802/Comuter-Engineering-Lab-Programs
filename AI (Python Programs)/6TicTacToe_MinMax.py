maxPlayer, minPlayer = 'x', 'o'

def evaluate(board):
    for i in range(3):
        # Check rows
        if len(set(board[i])) == 1 and board[i][0] != ' ':
            return 10 if board[i][0] == maxPlayer else -10
        # Check columns
        if len(set([board[j][i] for j in range(3)])) == 1 and board[0][i] != ' ':
            return 10 if board[0][i] == maxPlayer else -10
    # Check diagonals
    if len(set([board[i][i] for i in range(3)])) == 1 and board[0][0] != ' ':
        return 10 if board[0][0] == maxPlayer else -10
    if len(set([board[i][2 - i] for i in range(3)])) == 1 and board[0][2] != ' ':
        return 10 if board[0][2] == maxPlayer else -10
    return 0

def evaluate(board):
    for i in range(3):
        # Check rows
        if len(set(board[i])) == 1 and board[i][0] != ' ':
            return 10 if board[i][0] == 'x' else -10
        # Check columns
        if len(set([board[j][i] for j in range(3)])) == 1 and board[0][i] != ' ':
            return 10 if board[0][i] == 'x' else -10
    # Check diagonals
    if len(set([board[i][i] for i in range(3)])) == 1 and board[0][0] != ' ':
        return 10 if board[0][0] == 'x' else -10
    if len(set([board[i][2 - i] for i in range(3)])) == 1 and board[0][2] != ' ':
        return 10 if board[0][2] == 'x' else -10
    return 0

def game_over(board):
    score = evaluate(board)
    if score == 10 or score == -10:
        print("x won" if score == 10 else "o won")
        printBoard(board)
        return True
    if all([board[i][j] != ' ' for i in range(3) for j in range(3)]):
        print("It's a draw!")
        printBoard(board)
        return True
    return False

def minimax(board, depth, isMax):
    score = evaluate(board)
    if score == 10 or score == -10:
        return score
    best_score = -float('inf') if isMax else float('inf')
    for i in range(3):
        for j in range(3):
            if board[i][j] == ' ':
                board[i][j] = maxPlayer if isMax else minPlayer
                score = minimax(board, depth + 1, not isMax)
                board[i][j] = ' '
                if isMax:
                    best_score = max(score, best_score)
                else:
                    best_score = min(score, best_score)
    return best_score

def findBestMove(board, isMax):
    best_score = -float('inf') if isMax else float('inf')
    best_move = -1
    for i in range(3):
        for j in range(3):
            if board[i][j] == ' ':
                board[i][j] = maxPlayer if isMax else minPlayer
                score = minimax(board, 0, not isMax)
                board[i][j] = ' '
                if (isMax and score > best_score) or (not isMax and score < best_score):
                    best_score = score
                    best_move = i * 3 + j + 1
    return best_move

def printBoard(board):
    print()
    for i in range(3):
        row_str = ""
        for j in range(3):
            box_num = i * 3 + j + 1
            row_str += f" {board[i][j]} "
            if j != 2:
                row_str += "|"
        print(row_str)
        if i != 2:
            print("---+---+---")
    print()

if __name__ == "__main__":
    board = [[' ']*3 for _ in range(3)]
    printBoard(board)
    print("Hello User! Welcome")
    while True:
        choice = input("Play as [x/o]: ").lower()
        if choice in ['x', 'o']:
            break
    user, pc = (choice, 'o') if choice == 'x' else ('x', 'x')
    isMax = True if choice == 'x' else False
    while True:
        choice = input("Do you want to make the first move? [y/n]: ").lower()
        if choice in ['y', 'n']:
            break
    turn = "user" if choice == 'y' else "pc"
    while True:
        if turn == "user":
            print("Enter box number to place", user)
            box_num = int(input())
            row = (box_num - 1) // 3
            col = (box_num - 1) % 3
            if board[row][col] == ' ':
                board[row][col] = user
                printBoard(board)
                if game_over(board):
                    break
                turn = "pc"
            else:
                print("Invalid move! Box already filled.")
        else:
            bestMove = findBestMove(board, isMax)
            row = (bestMove - 1) // 3
            col = (bestMove - 1) % 3
            board[row][col] = pc
            printBoard(board)
            if game_over(board):
                break
            turn = "user"
    print("Game over!")
