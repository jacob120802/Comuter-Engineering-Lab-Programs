def is_valid(state):
    m1, c1, _, m2, c2 = state
    return 0 <= m1 <= 3 and 0 <= m2 <= 3 and 0 <= c1 <= 3 and 0 <= c2 <= 3 and (m1 == 0 or m1 >= c1) and (m2 == 0 or m2 >= c2)

def get_next_states(state):
    m1, c1, b, m2, c2 = state
    next_states = []
    moves = [(1, 0), (2, 0), (0, 2), (0, 1), (1, 1)]

    for dm, dc in moves:
        if b == 1:
            new_state = (m1 - dm, c1 - dc, 0, m2 + dm, c2 + dc)
        else:
            new_state = (m1 + dm, c1 + dc, 1, m2 - dm, c2 - dc)

        if is_valid(new_state):
            next_states.append(new_state)

    return next_states

def dfs(start_state):
    stack = [(start_state, [start_state])]

    while stack:
        current_state, path = stack.pop()

        if current_state == (0, 0, 0, 3, 3):
            return path

        for next_state in get_next_states(current_state):
            if next_state not in path:
                stack.append((next_state, path + [next_state]))

    return None

miss = int(input("Enter m: "))
canni = int(input("Enter c: "))

state = (miss, canni, 1, 0, 0)
solution = dfs(state)

if solution:
    print("Left\tRight")
    for path in solution:
        m1, c1, _, m2, c2 = path
        print("(", m1, c1, ")\t(", m2, c2, ")")
else:
    print("No solution")