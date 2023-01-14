# generating function:
# (1 + x^1)(1 + x^2)...(1 + x^n) where n is the number of bricks
# we need to find coefficient of x^n

# each iteration is multiplying the next term in the generating function

def solution(n):
    generating = [0 for _ in range(n + 1)]
    temp = []
    generating[0], generating[1] = 1, 1
    # [1, 1, 1, 1, 0, 0, 0, 0, 0, 0, ...]
    for i in range(2, n + 1): #3
        temp = generating[:]
        for j in range(((i - 1) * i / 2) + 1): #the max possible power is n(n+1)/2, the sum of the first n natural numbers. obtained from picking x^i for all i <= n
            if i + j > n: #we dont care about powers greater than n
                break
            generating[i + j] += temp[j]
        print(generating)
    return generating[n] - 1

print(solution(200))


