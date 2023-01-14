# find the shortest path length from (0,0) to (n-1,n-1) with 1 removal.

# sol: use a reach_without_break array of -1, 0, and 1:
# - -1 represents an unvisited node
# - 0 represents "impossible to reach without breaking"
# - 1 represents "possible to reach without breaking"

# if we reach an unvisited node with/without using a break, normal case, and add it to reach_without_break depending on whether a break was used.
# if we reach a visited node without a break, but reached it before with a break, consider that case.
# if we reach a visited node without a break, and reached it before without a break, skip this iteration, as it creates a cycle.
# if we reach a visited node with using a break, and reach_without_break of that node was 1 (possible to reach without breaking), ignore.

# the distance will be the number of "layers" of iterations of the BFS the entire time. it doesnt matter if there are cycles in this case, as each iteration checks if it is the end node.


def solution(map):
    rows = len(map)
    cols = len(map[0])
    reach_without_break = [[-1 for _ in range(cols)] for _ in range(rows)] # 
    # row, col, distance from (0,0), has a break left?
    q = [[0, 0, 0, True]]
    length = 1
    reach_without_break[0][0] = 1
    while length != 0:
        current = q[0][:]
        # print(q)
        q.pop(0)
        length -= 1
        row, col, dist, break_left = current[0], current[1], current[2], current[3]
        # check if we reached the end node
        if row == rows - 1 and col == cols - 1:
            return dist + 1
        # for all of the below, if there is a node in that direction, and either: 
        # - that node was unvisited, or 
        # - it was visited with no breaks left before (aka with a shorter dist) and now it is reached with a break remaining, 
        # then we will consider it
        # in each append, dist is incrememented by 1, as the neighboring nodes are 1 distance away from the current node.
        # left
        if row > 0 and (reach_without_break[row - 1][col] == -1 or (reach_without_break[row - 1][col] == 0 and break_left)):
            # if the node is a wall, we must use our break. if we dont have any left then skip this iteration and continue
            if map[row - 1][col] and break_left:
                q.append([row - 1, col, dist + 1, False])
                # add the status of the neighboring node (can or cannot be reached without a break) into visited for future iterations
                reach_without_break[row - 1][col] = False
                length += 1
            elif not map[row - 1][col]:
                q.append([row - 1, col, dist + 1, break_left])
                reach_without_break[row - 1][col] = break_left
                length += 1
        # right
        if row < rows - 1 and (reach_without_break[row + 1][col] == -1 or (reach_without_break[row + 1][col] == 0 and break_left)):
            if map[row + 1][col] and break_left:
                q.append([row + 1, col, dist + 1, False])
                reach_without_break[row + 1][col] = False
                length += 1
            elif not map[row + 1][col]:
                q.append([row + 1, col, dist + 1, break_left])
                reach_without_break[row + 1][col] = break_left
                length += 1
        # up
        if col > 0 and (reach_without_break[row][col - 1] == -1 or (reach_without_break[row][col - 1] == 0 and break_left)):
            if map[row][col - 1] and break_left:
                q.append([row, col - 1, dist + 1, False])
                reach_without_break[row][col - 1] = False
                length += 1
            elif not map[row][col - 1]:
                q.append([row, col - 1, dist + 1, break_left])
                reach_without_break[row][col - 1] = break_left
                length += 1
        # down
        if col < cols - 1 and (reach_without_break[row][col + 1] == -1 or (reach_without_break[row][col + 1] == 0 and break_left)):
            if map[row][col + 1] and break_left:
                q.append([row, col + 1, dist + 1, False])
                reach_without_break[row][col + 1] = False
                length += 1
            elif not map[row][col + 1]:
                q.append([row, col + 1, dist + 1, break_left])
                reach_without_break[row][col + 1] = break_left
                length += 1
    # if the graph is always solvable this will never run
    return "failed"

print(solution([[0,1,0,0],
            [1,1,0,0],
            [0,0,0,0]]))
    
print(solution([
    [0, 1, 0, 0], 
    [1, 1, 1, 1], 
    [0, 0, 0, 0],
    [0, 0, 1, 0],
    [0, 1, 1, 0]
    ]))

print(solution([
    [0, 1],
    [1, 0],
    [1, 0],
    [0, 0],
    [0, 0],
    [0, 0],
    [0, 0],
    [0, 0],
    [0, 0],
    [0, 0],
    [0, 0],
    [0, 0],
    [0, 1],
    [0, 0]
]))

print(solution([
    [0, 0, 0, 0], 
    [0, 0, 1, 1], 
    [0, 0, 1, 1], 
    [1, 1, 0, 0], 
    [1, 1, 0, 0]
    ]))


print(solution([
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0], 
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 
    [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0], 
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 
    [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0], 
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 
    [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0], 
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 
    [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0], 
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], 
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0], 
    ]))


