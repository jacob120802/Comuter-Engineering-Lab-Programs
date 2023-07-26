from collections import deque

def get_next_states(state, capacities):
    a, b = state
    ca, cb = capacities
    next_moves = []

    # Empty a and b
    next_moves.append((0, b))
    next_moves.append((a, 0))

    # Fill a and b to their maximum capacities
    next_moves.append((ca, b))
    next_moves.append((a, cb))

    # Pour water from a to b and vice versa
    amt = min(a, cb - b)
    next_moves.append((a - amt, b + amt))

    amt = min(ca - a, b)
    next_moves.append((a + amt, b - amt))

    return next_moves

def bfs(start, capacities, goal):
    q = deque()
    q.append((start, None))

    visited = set()
    visited.add(start)

    while q:
        current_state, parent = q.popleft()

        if current_state == goal:
            path = []
            while parent is not None:
                path.insert(0, current_state)
                current_state, parent = parent
            path.insert(0, current_state)
            return path

        for next_state in get_next_states(current_state, capacities):
            if next_state not in visited:
                q.append((next_state, (current_state, parent)))
                visited.add(next_state)

    return None

start = tuple(map(int, input("Enter start state for both jugs: ").split()))
capacities = tuple(map(int, input("Enter the maximum capacity of both jugs: ").split()))
goal = tuple(map(int, input("Enter the goal state for both jugs: ").split()))

path = bfs(start, capacities, goal)

if path:
    for state in path:
        print(state[0], ",", state[1])
    print("Found")
else:
    print("Not found")