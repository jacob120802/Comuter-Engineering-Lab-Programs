import copy
import heapq

goal = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]
initial_state = [[4, 2, 7], [5, 0, 1], [6, 8, 3]]

def get_blank_position(state):
    for i in range(3):
        for j in range(3):
            if state[i][j] == 0:
                return i, j

def heuristic(state):
    h = 0
    for i in range(3):
        for j in range(3):
            if state[i][j] != 0:
                x, y = divmod(state[i][j] - 1, 3)
                h += abs(i - x) + abs(j - y)
    return h

def is_valid(x, y):
    return 0 <= x < 3 and 0 <= y < 3

def reconstruct_path(came_from, current):
    path = []
    while current is not None:
        path.append(current)
        current = came_from[current]
    return path[::-1]

def best_first_search():
    queue = []
    heapq.heappush(queue, (heuristic(initial_state), initial_state))
    came_from = {}
    cost_so_far = {}
    came_from[tuple(map(tuple, initial_state))] = None
    cost_so_far[tuple(map(tuple, initial_state))] = 0
    while queue:
        _, current = heapq.heappop(queue)
        if current == goal:
            return reconstruct_path(came_from, tuple(map(tuple, current)))
        blank_x, blank_y = get_blank_position(current)
        moves = [(blank_x - 1, blank_y), (blank_x + 1, blank_y), (blank_x, blank_y - 1), (blank_x, blank_y + 1)]
        for move_x, move_y in moves:
            if is_valid(move_x, move_y):
                next_state = copy.deepcopy(current)
                next_state[blank_x][blank_y], next_state[move_x][move_y] = next_state[move_x][move_y], next_state[blank_x][blank_y]
                if tuple(map(tuple, next_state)) not in cost_so_far:
                    cost_so_far[tuple(map(tuple, next_state))] = float('inf')
                new_cost = cost_so_far[tuple(map(tuple, current))] + 1
                if new_cost < cost_so_far[tuple(map(tuple, next_state))]:
                    cost_so_far[tuple(map(tuple, next_state))] = new_cost
                    heapq.heappush(queue, (heuristic(next_state), next_state))
                    came_from[tuple(map(tuple, next_state))] = tuple(map(tuple, current))
    return []

result = best_first_search()
print("Initial state:  ", initial_state )
if result:
    print("Solution found in: ", len(result)-1, "moves")
    n=0
    for block in result:
        print("Step-",n,":")
        for row in block:
            print(row)
        print("---------")
        n=n+1
else:
    print("No solution")

