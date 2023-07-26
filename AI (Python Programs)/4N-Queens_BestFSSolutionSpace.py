import random

def print_board_top_border(N):
    print(" ", end="")
    for _ in range(N):
        print("----", end="")
    print("")

def draw_board(board):
    N = len(board)
    print_board_top_border(N)
    for queen_row in range(N):
        print(queen_row + 1, "|", end="")
        queen_col = board[queen_row]
        for j in range(N):
            if j == queen_col:
                print(" Q |", end="")
            else:
                print("   |", end="")
        print("")
        print_board_top_border(N)

def h(input):
    count = 0
    for queen_row in range(len(input)):
        queen_col = input[queen_row]
        for queen_2_row in range(len(input)):
            queen_2_col = input[queen_2_row]
            if queen_2_row == queen_row:
                continue
            if queen_2_row - queen_2_col == queen_row - queen_col:
                # same difference, collision along NW
                count += 1
            if queen_2_row + queen_2_col == queen_row + queen_col:
                # same sum, collision along NE SW direction
                count += 1
    return count

def move_gen(input):
    res = []
    N = len(input)
    for i in range(1, N):
        child = input[:]
        child[0], child[i] = child[i], child[0]
        if child not in open and child not in closed:
            res.append(child)
    return res

def isSoln(board):
    N = len(board)
    diagonal_collision = (h(board) > 0)
    two_queens_same_column = (len(set(board)) < N)
    return not (diagonal_collision or two_queens_same_column)

# Get user input for the number of queens
N = int(input("Enter the number of queens: "))
# Validate the input
while N < 4:
    print("Invalid input! Please enter a number greater than or equal to 4.")
    N = int(input("Enter the number of queens: "))
# Initialize the board
start = [i for i in range(N)]
random.shuffle(start)
open = [start]
closed = []
print("\nInput: \n")
draw_board(start)
print("\nOutput: \n")
while open:
    board = open.pop(0)
    if isSoln(board):
        draw_board(board)
        break
    else:
        closed = [board] + closed
        children = move_gen(board)
        open = sorted(children + open, key=lambda x: h(x))
print("")
