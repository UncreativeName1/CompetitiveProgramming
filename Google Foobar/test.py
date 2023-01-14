m = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

def without_row_col(r, c, ma):
    m = [[ma[x][y] for y in range(len(ma[0]))] for x in range(len(ma))]
    m.pop(r)
    for i in range(len(m)):
        m[i].pop(c)
    return m

print(m)
without_row_col(1, 1, m)
print(m)