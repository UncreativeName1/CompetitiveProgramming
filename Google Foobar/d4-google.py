
# Claim: (a, b) bananas will reach an end if and only if |a/gcd(a,b) + b/gcd(a,b)| is a power of 2.
# Notice that in the end state (x, x), their sum (which does not change) is 2x.
# It can be seen that x is the average of starting numbers (a, b). Also, the average of a and b
# is a power of 2 if and only if their sum is (specifically, it is the next power of 2). 
# If the sum of the two numbers (= 2x) is a power of 2, then so is x, their average, for x >= 1. 
# These pairs can also be multiplied by a constant multiple (e.g. (2, 6) -> (6, 18)).
# As such, we divide each number by the gcd to get rid of this possible variability.

# To pair up trainers, we start by taking the trainer with the least amount of pairings, and match
# them with the trainer with the least amount of pairings that also infinitely loops with them.


def gcd(x, y):
    while y:
       x, y = y, x % y
    return abs(x)

def is_power_2(a):
    return (a & (a - 1)) == 0;

def will_end(a, b):
    gcdd = gcd(a, b)
    sum = abs((a / gcdd) + (b / gcdd))
    return is_power_2(sum)

# exclude so that we can exclude a certain element (in usage: an element shouldnt pair with itself)
def smallest_pos_index(lst, indexes_to_iterate = 0):
    cur_small = 1073741824
    index = 0
    if indexes_to_iterate == 0:
        indexes_to_iterate = range(len(lst))
    for i in indexes_to_iterate:
        if lst[i] < cur_small and lst[i] > 0:
            cur_small = lst[i]
            index = i
    return [index, cur_small]

def all_zero(lst):
    for i in lst:
        if i != 0:
            return False
    return True

def solution(banana_list):
    total_pairs = 0
    length = len(banana_list)
    # if adj[row][col] is true, it means banana_list[row] and banana_list[col] will create an infinite loop. 0 means it cannot.
    adj = [[0 for _ in range(length)] for _ in range(length)]
    # the number of pairs each group of bananas can pair with
    amount_loops = [0 for _ in range(length)]
    for row in range(length):
        for col in range(length):
            # don't consider when the banana group is matched with itself. a valid pairing is when the two numbers do not sum to a perfect square in reduced form.
            if row != col and not will_end(banana_list[row], banana_list[col]):
                adj[row][col], adj[col][row] = 1, 1
                if col > row:
                    amount_loops[row] += 1
                    amount_loops[col] += 1
    # tracks the maximum possible amount of iterations to match pairs (should be floor(n/2))
    counter = (length // 2)
    # CURRENT INDEX; the index in banana_list of the element with the least amount of pairs but still has pairs.
    least_pair_index = smallest_pos_index(amount_loops)[0]
    # stores the current possible pairs with banana group of index least_pair_index
    pairs_index = []
    # print(adj)
    # print(amount_loops)
    while (counter != 0):
        counter -= 1
        # loop through the least_pair_index'th row in adj
        for i in range(length):
            if adj[least_pair_index][i] == 1:
                # set least_pair_index's row to 0 so future searches for a pair can't use this index
                adj[least_pair_index][i] = 0
                # same for least_pair_index's column to 0
                adj[i][least_pair_index] = 0
                # every possible pair is taken into account to find the pairing with the least other pairings.
                pairs_index.append(i)
        if len(pairs_index) == 0:
            continue
        # index in banana_list of the pair for this current element.
        pairing = smallest_pos_index(amount_loops, pairs_index)[0]
        total_pairs += 1
        # set these to 0 so they wont be iterated on.
        amount_loops[least_pair_index] = 0
        amount_loops[pairing] = 0
        # print("PAIRING: least_pair_index, pair", least_pair_index, pairing)
        # print(amount_loops)
        # set the pair's row and column in adj to 0 also so future searches dont use it
        for i in range(length):
            if adj[pairing][i] == 1:
                adj[i][pairing] = 0
                adj[pairing][i] = 0
                # update amount_loops to take into account the removal of this possible pair
                if amount_loops[i] > 0:
                    amount_loops[i] -= 1
        # update amount_loops for the original current group too
        for i in pairs_index:
            if amount_loops[i] > 0:
                amount_loops[i] -= 1
        # if there are no more possible pairings to make
        if all_zero(amount_loops):
            break
        least_pair_index = smallest_pos_index(amount_loops)[0]
        pairs_index = []
    return length - 2 * total_pairs

# print(solution([1, 7, 3, 21, 13, 19]))
# print(solution([1, 1]))
# [0, 0, 0, 1, 1, 1], 
# [0, 0, 1, 0, 1, 1], 
# [0, 1, 0, 0, 0, 1], 
# [1, 0, 0, 0, 1, 1], 
# [1, 1, 0, 1, 0, 0], 
# [1, 1, 1, 1, 0, 0]

# print(solution([6, 3]))

# print(solution([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19]))

# print(solution([1, 3, 7, 15, 31, 63]))
'''
[[0, 0, 0, 0, 0, 0], 
[0, 0, 1, 1, 1, 1], 
[0, 1, 0, 1, 1, 1], 
[0, 1, 1, 0, 1, 1], 
[0, 1, 1, 1, 0, 1], 
[0, 1, 1, 1, 1, 0]]

[0, 4, 4, 4, 4, 4]
'''


