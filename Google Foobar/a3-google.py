def gcd(x, y):
    while y:
       x, y = y, x % y
    return abs(x)

def lcm(a, b):
    return (a * b) / gcd(a, b) 

def frac_add(f1a, f2a, subtract):
    f1 = f1a[:]
    f2 = f2a[:]
    if f1[0] == 0:
        return [-f2[0], f2[1]] if subtract else f2
    if f2[0] == 0:
        return f1
    lcmm = lcm(f1[1], f2[1])
    f1[0] *= (lcmm / f1[1])
    f2[0] *= (lcmm / f2[1])
    if subtract:
        return [f1[0] - f2[0], lcmm]
    else:
        return [f1[0] + f2[0], lcmm]
        
def frac_multiply(f1a, f2a, divide):
    f1 = f1a[:]
    f2 = f2a[:]
    if divide:
        f2[0], f2[1] = f2[1], f2[0]
    return [f1[0] * f2[0], f1[1] * f2[1]]

def idm(size):
    idmatrix = []
    for i in range(size):
        idmatrix.append([])
        for j in range(size):
            if (i == j):
                idmatrix[i].append([1,1])
            else:
                idmatrix[i].append([0,1])
    return idmatrix

def matrix_subtract(m1a, m2):
    m1 = [[m1a[x][y] for y in range(len(m1a[0]))] for x in range(len(m1a))]
    for i in range(len(m2)):
        for j in range(len(m2)):
            m1[i][j] = frac_add(m1[i][j], m2[i][j], True)
    return m1

def matrix_multiply(m1, m2):
    res = []
    for i in range(len(m1)):
        res.append([])
        for j in range(len(m2[0])):
            summ = [0,1]
            for k in range(len(m2)):
                summ = frac_add(summ, frac_multiply(m1[i][k], m2[k][j], False), False) 
            res[i].append(summ)
    return res
    
def scalar_multiply(s, ma):
    m = [[ma[x][y] for y in range(len(ma[0]))] for x in range(len(ma))]
    for i in range(len(m)):
        for j in range(len(m[0])):
            m[i][j] = frac_multiply(m[i][j], s, False)
    return m

def without_row_col(r, c, ma):
    m = [[ma[x][y] for y in range(len(ma[0]))] for x in range(len(ma))]
    m.pop(r)
    for i in range(len(m)):
        m[i].pop(c)
    return m

def matrix_det(m):
    res = [0, 1]
    #print(m)
    #print("len: ", len(m))
    if len(m) == 1:
        return m[0][0]
    elif len(m) == 2:
        return frac_add(frac_multiply(m[0][0], m[1][1], False), frac_multiply(m[0][1], m[1][0], False), True)
    for i in range(len(m[0])):
        #print(m[0][i])
        #print(without_row_col(0, i, m))
        #print("part:")
        #print(matrix_det(without_row_col(0, i, m)))
        res = frac_add(res, frac_multiply(m[0][i], matrix_det(without_row_col(0, i, m)), False),  i % 2 == 1)
        #print(res)
    return res


def matrix_minor(m):
    size = len(m)
    res = [[0 for _ in range(size)] for _ in range(size)]
    for i in range(size):
        for j in range(size):
            #print("inputting: ") 
            #print(m)
            #print("without: i = ", i, ", j = ", j, " result: ")
            #print(without_row_col(i, j, m))
            res[i][j] = matrix_det(without_row_col(i, j, m))
    return res

def matrix_cofactor(ma):
    m = [[ma[x][y] for y in range(len(ma[0]))] for x in range(len(ma))]
    size = len(m)
    odd = False
    for i in range(size):
        if odd:
            for j in range((size + 1) // 2):
                m[i][2 * j][0] *= -1
        else:
            for j in range(size // 2):
                m[i][2 * j + 1][0] *= -1 
        odd = not odd
    return m

def matrix_transpose(ma):
    m = [[ma[x][y] for y in range(len(ma[0]))] for x in range(len(ma))]
    size = len(m)
    for i in range(size):
        for j in range(i + 1, size):
            m[i][j], m[j][i] = m[j][i], m[i][j]
    return m

def matrix_inverse(ma):
    m = [[ma[x][y] for y in range(len(ma[0]))] for x in range(len(ma))]
    #print(m)
    det_m = matrix_det(m)
    #print(det_m)
    det_m[0], det_m[1] = det_m[1], det_m[0]
    m = matrix_transpose(matrix_cofactor(matrix_minor(m)))
    return scalar_multiply(det_m, m)

def solution(m):
    nstates = len(m) #total number of states
    weight = [0 for i in range(nstates)] #total weight of that state's next state
    non_terminals = [] #transient state row #'s
    terminals = [] #absorbing state row #'s
    
    for i in range(nstates):
        for j in range(nstates):
            weight[i] += m[i][j]
        if (weight[i] == 0):
            terminals.append(i)
        else:
            non_terminals.append(i)
    
    t = len(non_terminals)
    s = len(terminals)

    #print(s)
    #print(t)
    #print(non_terminals)
    #print(terminals)
    if t == 0:
        ans = [0 for _ in range(nstates)]
        ans[0] = 1
        ans.append(1)
        return ans
    if s == 1:
        return [1]
    

    # Q = transient -> transient states
    # Q(i,j) = proability of going from i -> j, j is a transient state
    # R = transient -> absorbing states
    # R(i,j) = probability of going from i -> j, j is an absorbing state
    Q = [[0 for _ in range(t)] for _ in range(t)] # 2d array of pairs (a,b) represents a/b
    R = [[0 for _ in range(s)] for _ in range(t)] # 2d array of pairs (a,b) represents a/b

    # setting up Q and R
    ix, iy = 0, 0
    for i in non_terminals:
        for j in non_terminals:
            Q[ix][iy] = [m[i][j], weight[i]]
            iy += 1
        ix += 1
        iy = 0
    
    ix = 0
    for i in non_terminals:
        for j in terminals:
            R[ix][iy] = [m[i][j], weight[i]]
            #print(R)
            iy += 1
        ix += 1
        iy = 0
    
    idd = idm(t)

    #print(idd)
    #print(Q)
    #print(R)
    

    #print(matrix_subtract(idd, Q))
    
    N = matrix_inverse(matrix_subtract(idd, Q))

    #print(N)
    #print(R)
    
    # transient -> absorbing
    final = matrix_multiply(N, R)

    #print(final)

    
    prob = final[0][:]
    
    #print(prob)
    
    length = len(prob)
    
    cnt = length - 1
    lcmm = 1
    while cnt >= 0:
        lcmm = lcm(lcmm, prob[cnt][1])
        cnt -= 1
    
    for i in range(length):
        prob[i] = prob[i][0] * (lcmm / prob[i][1])
    
    prob.append(lcmm)

    length += 1
    
    #print(prob)

    cnt = length - 1 #2
    gcdd = 0
    while cnt >= 0:
        gcdd = gcd(gcdd, prob[cnt])
        cnt -= 1
    
    for i in range(length):
        prob[i] = abs(prob[i]) / gcdd
    
    return prob
    


print(solution([
    [0, 0, 0, 0, 0], 
    [0, 0, 0, 0, 0], 
    [0, 0, 0, 0, 0], 
    [0, 0, 0, 0, 0], 
    [0, 0, 0, 0, 0]]))

'''
print(solution([[0, 2, 1, 0, 0], #tr (3)
                [0, 0, 0, 3, 4], #tr (7)
                [0, 0, 0, 0, 0], #abs
                [0, 0, 0, 0,0], #abs
                [0, 0, 0, 0, 0]])) #abs
'''